# $NetBSD: Makefile,v 1.16 2012/09/07 19:16:06 adam Exp $
#

DISTNAME=	bmp-mac-0.1.1
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://distfiles.aydogan.net/audio/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://sourceforge.net/projects/mac-port/
COMMENT=	BMP plugin for Monkey's Audio files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/mac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
