# $NetBSD: Makefile,v 1.1 2020/10/02 10:25:03 ryoon Exp $

DISTNAME=	xroar-0.36.2
CATEGORIES=	emulators
MASTER_SITES=	https://www.6809.org.uk/xroar/dl/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.6809.org.uk/xroar/
COMMENT=	MC6809-based Dragon and Colour Computer (CoCo) emulator
LICENSE=	gnu-gpl-v3

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

GNU_CONFIGURE=	yes
INFO_FILES=	yes

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
