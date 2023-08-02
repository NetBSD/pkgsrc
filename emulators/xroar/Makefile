# $NetBSD: Makefile,v 1.14 2023/08/02 16:17:16 nia Exp $

DISTNAME=	xroar-1.0.2
PKGREVISION=	6
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
