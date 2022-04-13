# $NetBSD: Makefile,v 1.1 2022/04/13 08:31:25 pin Exp $

DISTNAME=	nsxiv-29
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nsxiv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nsxiv/nsxiv/
COMMENT=	Neo (or New or Not) Simple (or Small or Suckless) X Image Viewer
LICENSE=	gnu-gpl-v2

CONFLICTS=	sxiv-[0-9]*

MAKE_FLAGS+=	PREFIX=${PREFIX} MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	HAVE_INOTIFY=0

USE_LANGUAGES=	c99

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
