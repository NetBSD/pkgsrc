# $NetBSD: Makefile,v 1.110 2018/11/14 22:21:39 kleink Exp $

# Note that upstream has replaced tarballs without changing the
# version number (e.g., 0.19.2 had two different tarballs).
# Therefore, it is suggested to wait a week after a release before
# updating pkgsrc.
DISTNAME=		ufraw-0.22
PKGNAME=		gimp-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config msgfmt
USE_TOOLS+=		perl:run pod2man
USE_LANGUAGES=		c c++03

CONFIGURE_ARGS+=	--enable-mime

GCONF_SCHEMAS=		ufraw.schemas

PTHREAD_AUTO_VARS=	yes

# This package uses too much C99 code to be patched.
GCC_REQD+=		3.0
BUILDLINK_TRANSFORM+=	rm:-std=gnu99

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
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
