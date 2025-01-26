# $NetBSD: Makefile,v 1.1 2025/01/26 15:12:27 wiz Exp $

# mtpaint's maintainer uses commits as releases.
DISTNAME=	mtpaint-3.50.11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wjaguar/}
GITHUB_TAG=	f37cf09c02b0ebd81d29c67be9741f54d76a9171
WRKSRC=		${WRKDIR}/mtPaint-${GITHUB_TAG}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mtpaint.sourceforge.net/
COMMENT=	Painting program and photo editor
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	cflags jpeg jp2v2 webp intl tiff man
USE_TOOLS+=		gmake pkg-config

.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
