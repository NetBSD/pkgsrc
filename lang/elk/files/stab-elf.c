/* $NetBSD: stab-elf.c,v 1.3 2000/10/22 20:42:48 agc Exp $ */

/*
 * Copyright (c) 2000 Alistair G. Crooks.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Alistair G. Crooks.
 * 4. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <sys/cdefs.h>

#ifndef lint
__COPYRIGHT(
	"@(#) Copyright (c) 2000 \
	        The NetBSD Foundation, Inc.  All rights reserved.");
__RCSID("$NetBSD: stab-elf.c,v 1.3 2000/10/22 20:42:48 agc Exp $");
#endif

#include <sys/types.h>
#include <sys/param.h>

#include <elf.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef AWK
#define AWK	"/usr/bin/awk"
#endif

#ifndef NM
#define NM	"/usr/bin/nm"
#endif

#ifdef __ELF__
#define NAME_OFFSET	0
#else
#define NAME_OFFSET	1
#endif

SYMTAB *
Open_File_And_Snarf_Symbols (name)
     char *name;
{
	SYMTAB	*tab = NULL;
	FILE	*pp;
	char	cmd[MAXPATHLEN + 200];
	char	buf[BUFSIZ];
	SYM	**nextp;
	SYM	*sp;

	(void) snprintf(cmd, sizeof(cmd), "%s -g %s | %s '$2 == \"T\" { printf(\"%%s %%s\\n\", $1 $3) }'", NM, name, AWK);
	if ((pp = popen(cmd, "r")) == NULL) {
		Primitive_Error("can't open a.out file");
	}
	tab = (SYMTAB *)Safe_Malloc (sizeof (SYMTAB));
	tab->first = 0;
	tab->strings = 0;
	nextp = &tab->first;
	while (fgets(buf, sizeof(buf), pp) != NULL) {
		sp = (SYM *)Safe_Malloc(sizeof (SYM));
		sp->name = Safe_Malloc(strlen(buf) + 1 - 8 - 1);
		(void) strcpy(sp->name, &buf[8 + 1 + NAME_OFFSET]);
		(void) sscanf(buf, "%08x", &sp->value);
		*nextp = sp;
		nextp = &sp->next;
		*nextp = 0;
	}
	(void) pclose(pp);
	return tab;
}
