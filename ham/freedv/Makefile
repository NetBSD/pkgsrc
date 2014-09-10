# $NetBSD: Makefile,v 1.3 2014/09/10 12:16:15 joerg Exp $
#

VERSION=	0.97.0.1696
PKGNAME=	freedv-${VERSION}
DISTNAME=	fdmdv2-${VERSION}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/fdmdv2
CATEGORIES=	ham
#  svn://svn.code.sf.net/p/freetel/code/fdmdv2
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	http://freedv.org/
COMMENT=	FreeDV: HF Digital Voice for Radio Amateurs

LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=c c++

CHECK_PORTABILITY_SKIP+= configure

USE_CMAKE=yes
CONFIGURE_DIRS=build
BUILD_DIRS=${CONFIGURE_DIRS}
CMAKE_ARG_PATH=..

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../ham/codec2/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../audio/sox/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
