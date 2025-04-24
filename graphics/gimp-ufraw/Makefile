# $NetBSD: Makefile,v 1.156 2025/04/24 14:14:20 wiz Exp $

DISTNAME=		ufraw-0.22
PKGNAME=		gimp-${DISTNAME}
PKGREVISION=		51
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://ufraw.sourceforge.net/
COMMENT=		Converter from camera RAW

LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config msgfmt
USE_TOOLS+=		perl:run pod2man
USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99

CONFIGURE_ARGS+=	--enable-mime

GCONF_SCHEMAS=		ufraw.schemas

# \todo Understand why pthread is present at all and remove it.
PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/gtkimageview/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
