# $NetBSD: Makefile,v 1.1 2020/06/14 07:45:49 ryoon Exp $

DISTNAME=	visualboyadvance-m-2.1.4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=visualboyadvance-m/}
GITHUB_PROJECT=	visualboyadvance-m
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://vba-m.com/
COMMENT=	Game Boy and Game Boy Advance Emulator
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgmerge

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
