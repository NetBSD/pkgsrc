# $NetBSD: Makefile,v 1.18 2025/02/12 06:44:48 ryoon Exp $

DISTNAME=	xroar-1.4.2
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	https://www.6809.org.uk/xroar/dl/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.6809.org.uk/xroar/
COMMENT=	MC6809-based Dragon and Colour Computer (CoCo) emulator
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
INFO_FILES=	yes

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

.include "options.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
