# $NetBSD: Makefile,v 1.17 2024/10/20 14:03:44 wiz Exp $

DISTNAME=	mednaffe-0.9.2
PKGREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=AmatCoder/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/AmatCoder/mednaffe
COMMENT=	Graphical interface for the Mednafen multi-system emulator
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

DEPENDS+=	mednafen>=0:../../emulators/mednafen

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
