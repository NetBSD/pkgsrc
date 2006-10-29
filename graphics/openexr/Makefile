# $NetBSD: Makefile,v 1.12 2006/10/29 13:51:18 dsainty Exp $

DISTNAME=	openexr-1.4.0a
PKGNAME=	openexr-1.4.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	${WRKSRC}/OpenExr.pc.in
TEST_TARGET=		check
PTHREAD_OPTS+=		require

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
LDFLAGS+=		-lmx
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
