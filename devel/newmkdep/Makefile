# $NetBSD: Makefile,v 1.6 2002/08/01 13:06:58 wiz Exp $

DISTNAME=	newmkdep-1.0
CATEGORIES=	devel
MASTER_SITES=	http://core.de/~tron/

MAINTAINER=	packages@netbsd.org
COMMENT=	faster replacement for *BSD's "mkdep"

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/newmkdep

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-I/usr/include -I${ZOULARISBASE}/include
LDFLAGS+=	-L${ZOULARISBASE}/lib -lbsdcompat
.endif

.include "../../mk/bsd.pkg.mk"
