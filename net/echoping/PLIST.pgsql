@comment $NetBSD: PLIST.pgsql,v 1.1 2007/04/09 14:44:30 adrianp Exp $
lib/echoping/postgresql.la
man/man1/echoping_postgresql.1
@unexec ${RMDIR} %D/lib/echoping 2>/dev/null || ${TRUE}
