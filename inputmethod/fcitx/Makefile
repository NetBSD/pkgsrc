# $NetBSD: Makefile,v 1.1.1.1 2006/01/16 13:04:07 rxg Exp $
#

DISTNAME=		fcitx-3.1.1
CATEGORIES=		inputmethod
MASTER_SITES=		http://www.fcitx.org/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://www.fcitx.org/
COMMENT=		Free Chinese Input Toy of X

USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-xft

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
