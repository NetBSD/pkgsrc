/*
  $NetBSD: pkg_filecheck.c,v 1.1.1.1 2003/07/13 16:15:34 wiz Exp $

  pkg_filecheck.c -- check for files not owned by any package
  Copyright (C) 2001 Dieter Baron

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
  3. The name of the author may not be used to endorse or promote
     products derived from this software without specific prior
     written permission.
 
  THIS SOFTWARE IS PROVIDED BY DIETER BARON ``AS IS'' AND ANY EXPRESS
  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED.  IN NO EVENT SHALL DIETER BARON BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <db.h>
#include <errno.h>
#include <fcntl.h>
#include <fts.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct array {
    void **p;
    int len, alen;
};

char *prg;

static int check(char **dir, DB **db, char **ignore);
static int fts_sort(const FTSENT **e1, const FTSENT **e2);
static void push(struct array *a, void *el);
static int read_conf(char *fname, char ***dirp, DB ***dbp, char ***ignorep);



int
main(int argc, char *argv[])
{
    DB **db;
    char **dir, **ignore;

    char *cfgfile;
    int c, i, err;

    prg = argv[0];
    opterr = 0;

    cfgfile = "@PKG_SYSCONFDIR@/pkg_filecheck.conf";

    while ((c=getopt(argc, argv, "c:h")) != -1) {
	switch (c) {
	case 'c':
	    cfgfile = optarg;
	    break;

	case 'h':
	    printf("usage: %s [-h] [-c config-file]\n", prg);
	    exit(0);

	default:
	    fprintf(stderr, "usage: %s [-h] [-c config-file]\n", prg);
	    exit(1);
	}
    }

    if (read_conf(cfgfile, &dir, &db, &ignore) < 0)
	exit(1);

    err = check(dir, db, ignore);

    for (i=0; db[i]; i++)
	db[i]->close(db[i]);
    free(dir);
    free(db);
    free(ignore);

    exit(err ? 1 : 0);
}



static int
check(char **dir, DB **db, char **ignore)
{
    FTS *fts;
    FTSENT *ent;
    DBT key, val;
    int i, found;

    if ((fts=fts_open(dir, FTS_PHYSICAL, fts_sort)) == NULL) {
	fprintf(stderr, "%s: cannot walk direcotry hierarchy: %s",
		prg, strerror(errno));
	return -1;
    }

    while ((ent=fts_read(fts))) {
	switch (ent->fts_info) {
	case FTS_F:
	    key.data = ent->fts_path;
	    key.size = ent->fts_pathlen+1;
	    
	    found = 0;
	    for (i=0; db[i]; i++)
		if (db[i]->get(db[i], &key, &val, 0) == 0) {
		    found = 1;
		    break;
		}

	    if (!found)
		printf("%s\n", ent->fts_path);
	    break;

	case FTS_D:
	    if (ignore)
		for (i=0; ignore[i]; i++)
		    if (strcmp(ignore[i], ent->fts_path) == 0) {
			fts_set(fts, ent, FTS_SKIP);
			break;
		    }
	    break;

	case FTS_DNR:
	    fprintf(stderr, "%s: cannot read directory `%s', skipped: %s\n",
		    prg, ent->fts_path, strerror(ent->fts_errno));
	    break;

	case FTS_NS:
	    fprintf(stderr, "%s: cannot stat file `%s', skipped: %s\n",
		    prg, ent->fts_path, strerror(ent->fts_errno));
	    break;

	case FTS_ERR:
	    fprintf(stderr, "%s: directory traversal error: %s\n",
		    prg, strerror(ent->fts_errno));
	    break;

	case FTS_DC:
	case FTS_DP:
	case FTS_SL:
	case FTS_SLNONE:
	case FTS_DEFAULT:
	    /* ignore */
	    break;

	default:
	    fprintf(stderr, "%s: unknown FTSENT type %d ignored\n",
		    prg, ent->fts_info);
	    break;
	}
    }

    fts_close(fts);
    return 0;
}



static int
fts_sort(const FTSENT **e1, const FTSENT **e2)
{
    return strcmp((*e1)->fts_name, (*e2)->fts_name);
}



static int
read_conf(char *fname, char ***dirp, DB ***dbp, char ***ignorep)
{
    struct array dir, db, ignore;
    FILE *f;
    DB *cdb;
    char b[8192], *curd, *dbname, *cmd, *p;
    int lineno, err;

    dir.p = db.p = ignore.p = NULL;
    dir.len = db.len = ignore.len = 0;
    dir.alen = db.alen = ignore.alen = 0;

    if ((f=fopen(fname, "r")) == NULL) {
	fprintf(stderr, "%s: cannot open config file `%s': %s\n",
		prg, fname, strerror(errno));
	return -1;
    }

    curd = NULL;

    lineno = 0;
    while (fgets(b, 8192, f)) {
	lineno++;
	if (b[0] == '#')
	    continue;

	cmd = b+strspn(b, " \t");
	p = cmd+strcspn(cmd, " \t\n");
	*(p++) = '\0';
	p += strspn(p, " \t");
	if (*p == '\n' || *p == '\0')
	    continue;

	if (p[strlen(p)-1] == '\n')
	    p[strlen(p)-1] = '\0';

	if (strcmp(cmd, "dir") == 0) {
	    free(curd);
	    curd = strdup(p);
	}
	else if (strcmp(cmd, "db") == 0) {
	    if (curd) {
		dbname = malloc(strlen(curd) + strlen(p) + 2);
		sprintf(dbname, "%s/%s", curd, p);
	    }
	    else
		dbname = p;
	    if ((cdb=dbopen(dbname, O_RDONLY, 0, DB_BTREE, NULL)) == NULL) {
		fprintf(stderr, "%s:%s:%d: cannot open data base `%s': %s\n",
			prg, fname, lineno, dbname, strerror(errno));
		free(dir.p);
		free(db.p);
		free(ignore.p);
		return -1;
	    }
	    else
		push(&db, cdb);

	    if (curd)
		free(dbname);
	}
	else if (strcmp(cmd, "check") == 0)
	    push(&dir, strdup(p));
	else if (strcmp(cmd, "ignore") == 0)
	    push(&ignore, strdup(p));
	else {
	    fprintf(stderr, "%s:%s:%d: unrecognized command `%s'\n",
		    prg, fname, lineno, cmd);
	}
    }

    fclose(f);

    err = 0;

    if (dir.p == NULL) {
	fprintf(stderr, "%s: no directories to check\n",
		prg);
	err = 1;
    }
    if (db.p == NULL) {
	fprintf(stderr, "%s: no file data bases given\n",
		prg);
	err = 1;
    }

    if (err) {
	free(dir.p);
	free(db.p);
	free(ignore.p);
	return -1;
    }

    *dirp = (char **)dir.p;
    *dbp = (DB **)db.p;
    *ignorep = (char **)ignore.p;

    return 0;
}



static void
push(struct array *a, void *el)
{
    int alen;
    void *p;

    if (a->len + 2 > a->alen) {
	if (a->alen > 1024)
	    alen = a->alen+1024;
	else 
	    alen = a->alen * 2;

	if ((p=realloc(a->p, alen*sizeof(void *))) == NULL) {
	    fprintf(stderr, "%s: malloc failure\n", prg);
	    exit(1);
	}
	
	a->p = p;
	a->alen = alen;
    }

    a->p[a->len++] = el;
    a->p[a->len] = NULL;
}
