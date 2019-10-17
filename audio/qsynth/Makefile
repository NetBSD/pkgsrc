# $NetBSD: Makefile,v 1.52 2019/10/17 08:20:43 nia Exp $

DISTNAME=	qsynth-0.5.7
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qsynth/}
CATEGORIES=	audio

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://qsynth.sourceforge.io/qsynth-index.html
COMMENT=	Qt GUI Interface to FluidSynth
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
