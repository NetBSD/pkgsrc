# $NetBSD: Makefile,v 1.7 2023/10/24 22:11:02 wiz Exp $

DISTNAME=	WCMCommander-0.20.0
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=corporateshark/}
GITHUB_PROJECT=	WCMCommander
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wcm.linderdaum.com/
COMMENT=	Two-panel file manager
#LICENSE=	mit # includes fonts with perhaps other licenses

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-release-/}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
CMAKE_ARGS+=	-DWITH_SMBCLIENT:BOOL=OFF

# Needs gnu for alloca builtin
FORCE_CXX_STD=	gnu++11

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
