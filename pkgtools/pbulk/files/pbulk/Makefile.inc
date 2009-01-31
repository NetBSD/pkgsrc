# $NetBSD: Makefile.inc,v 1.4 2009/01/31 23:25:38 joerg Exp $

BINDIR?=	${PREFIX}/bin

WARNS=		4

.if !defined(LIBPBULK_ONLY)
CPPFLAGS+=	-I${.CURDIR}/../lib
DPADD+=		${.OBJDIR}/../lib/libpbulk.a
LDADD+=		-L${.OBJDIR}/../lib -lpbulk
.endif

LDADD+=		-lnbcompat
