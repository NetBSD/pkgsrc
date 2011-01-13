# $NetBSD: Makefile,v 1.29 2011/01/13 13:37:35 wiz Exp $

DISTNAME=	hatari-1.4.0
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://download.berlios.de/hatari/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hatari.berlios.de/
COMMENT=	Atari ST emulator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
#USE_TOOLS+=		gmake
#GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/hatari

.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
