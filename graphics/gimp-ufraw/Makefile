# $NetBSD: Makefile,v 1.75 2012/10/02 17:11:11 tron Exp $

DISTNAME=		ufraw-0.18
PKGNAME=		gimp-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config msgfmt
USE_TOOLS+=		perl:run pod2man
USE_LANGUAGES=		c c++

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
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
