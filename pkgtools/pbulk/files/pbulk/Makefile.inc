# $NetBSD: Makefile.inc,v 1.1.1.1 2007/06/19 19:49:55 joerg Exp $

BINDIR?=	${PREFIX}/bin

WARNS=		4

.if !defined(LIBPBULK_ONLY)
CPPFLAGS+=	-I${.CURDIR}/../lib
DPADD+=		${.OBJDIR}/../lib/libpbulk.a
LDADD+=		-L${.OBJDIR}/../lib -lpbulk
.endif

.if !defined(NO_LIBEVENT_NEEDED)
CPPFLAGS+=
.if !defined(LIBPBULK_ONLY)
LDADD+=		-levent
.endif
.endif
