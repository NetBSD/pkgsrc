# $NetBSD: Makefile,v 1.78 2024/01/30 14:21:33 ryoon Exp $
#

DISTNAME=	paman-0.9.4
PKGREVISION=	71
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/paman/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/paman/
COMMENT=	GTK frontend for the PulseAudio sound server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config gmake

CONFIGURE_ARGS+=	--disable-lynx

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
