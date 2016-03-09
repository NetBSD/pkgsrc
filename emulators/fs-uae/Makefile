# $NetBSD: Makefile,v 1.3 2016/03/09 22:08:46 tnn Exp $

DISTNAME=	fs-uae-2.6.2
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/fs-uae/stable/${PKGVERSION_NOREV}/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fs-uae.net/
COMMENT=	FS-UAE Amiga Emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config zip
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../audio/openal/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.endif
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
