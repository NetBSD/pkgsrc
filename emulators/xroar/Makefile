# $NetBSD: Makefile,v 1.13 2023/07/09 21:48:44 nia Exp $

DISTNAME=	xroar-1.0.2
PKGREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	https://www.6809.org.uk/xroar/dl/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.6809.org.uk/xroar/
COMMENT=	MC6809-based Dragon and Colour Computer (CoCo) emulator
LICENSE=	gnu-gpl-v3

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=	c99

GNU_CONFIGURE=	yes
INFO_FILES=	yes

.include "options.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
