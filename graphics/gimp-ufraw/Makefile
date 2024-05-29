# $NetBSD: Makefile,v 1.145 2024/05/29 16:32:53 adam Exp $

DISTNAME=		ufraw-0.22
PKGNAME=		gimp-${DISTNAME}
PKGREVISION=		41
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

# There have been issues with unstable OPENMP APIs.  Therefore,
# updates must be tested on NetBSD 9 with gcc.
MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config msgfmt
USE_TOOLS+=		perl:run pod2man
USE_LANGUAGES=		c99 c++

# exiv2 is declared to need filesystem, but as of 2023-08 it fails if
# called with --std=c++03.  We avoid forcing std.  (pkgsrc lacks a
# mechanism to declare which --stds are acceptable and thus exiv2
# doesn't declare this.)

CONFIGURE_ARGS+=	--enable-mime

GCONF_SCHEMAS=		ufraw.schemas

PTHREAD_AUTO_VARS=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.ufraw
PKG_SUPPORTED_OPTIONS=	lensfun
PKG_SUGGESTED_OPTIONS=	lensfun
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mlensfun)
.include "../../graphics/lensfun/buildlink3.mk"
.endif

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/gtkimageview/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
