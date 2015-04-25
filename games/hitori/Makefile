# $NetBSD: Makefile,v 1.4 2015/04/25 14:22:56 tnn Exp $

DISTNAME=	hitori-3.14.3
PKGREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/hitori/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Apps/Hitori
COMMENT=	Logic game similar to Sudoku
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
