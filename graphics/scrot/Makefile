# $NetBSD: Makefile,v 1.42 2021/08/14 08:12:46 nia Exp $

DISTNAME=	scrot-1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=resurrecting-open-source-projects/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/resurrecting-open-source-projects/scrot
COMMENT=	Command line screen capture util like "import", but using imlib2
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
