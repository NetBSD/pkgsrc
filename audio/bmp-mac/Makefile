# $NetBSD: Makefile,v 1.40 2020/12/03 13:24:03 zafer Exp $
#

DISTNAME=	bmp-mac-0.1.1
PKGREVISION=	32
CATEGORIES=	audio
MASTER_SITES=	https://www.aydogan.net/distfiles/audio/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://sourceforge.net/projects/mac-port/
COMMENT=	BMP plugin for Monkey's Audio files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/mac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
