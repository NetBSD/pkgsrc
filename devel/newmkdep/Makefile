# $NetBSD: Makefile,v 1.9 2003/07/17 21:31:58 grant Exp $

DISTNAME=	newmkdep-1.0
WRKSRC=		${WRKDIR}/newmkdep
CATEGORIES=	devel
MASTER_SITES=	http://core.de/~tron/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	faster replacement for *BSD's "mkdep"

NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-I/usr/include -I${ZOULARISBASE}/include
LDFLAGS+=	-L${ZOULARISBASE}/lib -lbsdcompat
.endif

.include "../../mk/bsd.pkg.mk"
