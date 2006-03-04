# $NetBSD: Makefile,v 1.5 2006/03/04 21:30:10 jlam Exp $

DISTNAME=	cstream-2.2
CATEGORIES=	misc
MASTER_SITES=	http://www.cons.org/cracauer/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=       http://www.cons.org/cracauer/
COMMENT=	General-purpose stream-handling tool with bandwidth limiting

GNU_CONFIGURE=  yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

.include "../../mk/bsd.pkg.mk"
