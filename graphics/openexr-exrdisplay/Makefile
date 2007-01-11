# $NetBSD: Makefile,v 1.1 2007/01/11 19:03:05 drochner Exp $

DISTNAME=	openexr-1.4.0a
PKGNAME=	openexr-exrdisplay-1.4.0
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	GUI for openexr

CONFLICTS+=	openexr<1.4.0nb1
PATCHDIR=	${.CURDIR}/../../graphics/openexr/patches
DISTINFO_FILE=	${.CURDIR}/../../graphics/openexr/distinfo

WRKSRC=			${WRKDIR}/openexr-1.4.0
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

BUILD_DIRS=		exrdisplay
INSTALL_DIRS=		exrdisplay

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
LDFLAGS+=		-lmx
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
