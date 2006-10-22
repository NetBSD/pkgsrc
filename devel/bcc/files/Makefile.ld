# $NetBSD: Makefile.ld,v 1.1 2006/10/22 06:31:43 rillig Exp $
#

PROG=		ld86
SRCS=		dumps.c io.c ld.c readobj.c table.c typeconv.c writebin.c
CPPFLAGS+=	-DBSD_A_OUT -DSTANDARD_GNU_A_OUT
WARNS=		0

.include <bsd.prog.mk>
