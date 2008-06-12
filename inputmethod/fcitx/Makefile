# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:33 joerg Exp $
#

DISTNAME=		fcitx-3.1.1
PKGREVISION=		2
CATEGORIES=		inputmethod
MASTER_SITES=		http://www.fcitx.org/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://www.fcitx.org/main/
COMMENT=		Free Chinese Input Toy of X

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-xft

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
