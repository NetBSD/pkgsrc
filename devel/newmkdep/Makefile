# $NetBSD: Makefile,v 1.11 2004/01/20 12:13:28 agc Exp $

DISTNAME=	newmkdep-1.0
CATEGORIES=	devel
MASTER_SITES=	http://core.de/~tron/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Faster replacement for *BSD's "mkdep"

WRKSRC=		${WRKDIR}/newmkdep
NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-I/usr/include -I${ZOULARISBASE}/include
LDFLAGS+=	-L${ZOULARISBASE}/lib -lbsdcompat
.endif

.include "../../mk/bsd.pkg.mk"
