# $NetBSD: Makefile,v 1.4 2007/12/29 10:09:07 wiz Exp $
#

DISTNAME=	bmp-mac-0.1.1
CATEGORIES=	audio
MASTER_SITES=	http://bsd.cenkes.org/myports/

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
