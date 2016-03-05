# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:27 jperkin Exp $

DISTNAME=	WCMCommander-0.20.0
PKGREVISION=	1
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

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
