# $NetBSD: Makefile,v 1.10 2022/08/11 05:08:21 gutteridge Exp $

DISTNAME=	visualboyadvance-m-2.1.4
PKGREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=visualboyadvance-m/}
GITHUB_PROJECT=	visualboyadvance-m
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://vba-m.com/
COMMENT=	Game Boy and Game Boy Advance Emulator
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgmerge zip

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
