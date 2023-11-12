# $NetBSD: Makefile,v 1.48 2023/11/12 13:22:17 wiz Exp $

DISTNAME=	scrot-1.10
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=resurrecting-open-source-projects/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/resurrecting-open-source-projects/scrot
COMMENT=	Command line screen capture util like "import", but using imlib2
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
