# $NetBSD: Makefile,v 1.1 2016/02/04 13:49:06 leot Exp $
#

DISTNAME=	sxiv-1.3.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=muennich/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://github.com/muennich/sxiv
COMMENT=	Simple (or small or suckless) X Image Viewer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX} MANPREFIX=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
