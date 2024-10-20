# $NetBSD: Makefile,v 1.49 2024/10/20 14:03:20 wiz Exp $
#

DISTNAME=	bmp-mac-0.1.1
PKGREVISION=	40
CATEGORIES=	audio
MASTER_SITES=	https://www.aydogan.net/distfiles/audio/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://sourceforge.net/projects/mac-port/
COMMENT=	BMP plugin for Monkey's Audio files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# Workaround for glib2-2.68.0 c++ fallout.
CXXFLAGS+=	-DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_66

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/mac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
