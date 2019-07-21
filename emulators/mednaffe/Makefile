# $NetBSD: Makefile,v 1.2 2019/07/21 22:24:46 wiz Exp $

DISTNAME=	mednaffe-0.8.8
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=AmatCoder/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/AmatCoder/mednaffe
COMMENT=	Graphical interface for the Mednafen multi-system emulator
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

DEPENDS+=	mednafen>=0:../../emulators/mednafen

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
