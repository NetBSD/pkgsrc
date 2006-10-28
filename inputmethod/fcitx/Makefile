# $NetBSD: Makefile,v 1.4 2006/10/28 21:29:47 wiz Exp $
#

DISTNAME=		fcitx-3.1.1
PKGREVISION=		2
CATEGORIES=		inputmethod
MASTER_SITES=		http://www.fcitx.org/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://www.fcitx.org/main/
COMMENT=		Free Chinese Input Toy of X

USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-xft

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
