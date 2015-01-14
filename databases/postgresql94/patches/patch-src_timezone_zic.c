$NetBSD: patch-src_timezone_zic.c,v 1.1 2015/01/14 21:01:18 adam Exp $

--- src/timezone/zic.c.orig	2010-03-16 07:17:04.000000000 +0000
+++ src/timezone/zic.c
@@ -121,51 +121,51 @@ struct zone
 
 extern int	link(const char *fromname, const char *toname);
 static void addtt(const pg_time_t starttime, int type);
-static int addtype(long gmtoff, const char *abbr, int isdst,
-		int ttisstd, int ttisgmt);
-static void leapadd(const pg_time_t t, int positive, int rolling, int count);
+static int addtype(const long gmtoff, const char *abbr, const int isdst,
+		const int ttisstd, const int ttisgmt);
+static void leapadd(const pg_time_t t, const int positive, const int rolling, int count);
 static void adjleap(void);
 static void associate(void);
 static int	ciequal(const char *ap, const char *bp);
-static void convert(long val, char *buf);
+static void convert(const long val, char *buf);
 static void dolink(const char *fromfile, const char *tofile);
 static void doabbr(char *abbr, const char *format,
-	   const char *letters, int isdst, int doquotes);
-static void eat(const char *name, int num);
-static void eats(const char *name, int num,
-	 const char *rname, int rnum);
-static long eitol(int i);
+	   const char *letters, const int isdst, int doquotes);
+static void eat(const char *name, const int num);
+static void eats(const char *name, const int num,
+	 const char *rname, const int rnum);
+static long eitol(const int i);
 static void error(const char *message);
 static char **getfields(char *buf);
 static long gethms(const char *string, const char *errstrng,
-	   int signable);
+	   const int signable);
 static void infile(const char *filename);
-static void inleap(char **fields, int nfields);
-static void inlink(char **fields, int nfields);
-static void inrule(char **fields, int nfields);
-static int	inzcont(char **fields, int nfields);
-static int	inzone(char **fields, int nfields);
-static int	inzsub(char **fields, int nfields, int iscont);
+static void inleap(char **fields, const int nfields);
+static void inlink(char **fields, const int nfields);
+static void inrule(char **fields, const int nfields);
+static int	inzcont(char **fields, const int nfields);
+static int	inzone(char **fields, const int nfields);
+static int	inzsub(char **fields, const int nfields, const int iscont);
 static int	itsabbr(const char *abbr, const char *word);
 static int	itsdir(const char *name);
 static int	lowerit(int c);
 static char *memcheck(char *tocheck);
 static int	mkdirs(char *filename);
 static void newabbr(const char *abbr);
-static long oadd(long t1, long t2);
-static void outzone(const struct zone * zp, int ntzones);
-static void puttzcode(long code, FILE *fp);
+static long oadd(const long t1, const long t2);
+static void outzone(const struct zone * zp, const int ntzones);
+static void puttzcode(const long code, FILE *fp);
 static int	rcomp(const void *leftp, const void *rightp);
-static pg_time_t rpytime(const struct rule * rp, int wantedy);
+static pg_time_t rpytime(const struct rule * rp, const int wantedy);
 static void rulesub(struct rule * rp,
 		const char *loyearp, const char *hiyearp,
 		const char *typep, const char *monthp,
 		const char *dayp, const char *timep);
 static void setboundaries(void);
-static pg_time_t tadd(const pg_time_t t1, long t2);
+static pg_time_t tadd(const pg_time_t t1, const long t2);
 static void usage(FILE *stream, int status);
 static void writezone(const char *name, const char *string);
-static int	yearistype(int year, const char *type);
+static int	yearistype(const int year, const char *type);
 
 static int	charcnt;
 static int	errors;
