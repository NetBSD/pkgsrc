# $NetBSD: Makefile,v 1.4 2015/04/25 14:24:47 tnn Exp $

DISTNAME=	pdfmod-0.9.1
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pdfmod/0.9/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://wiki.gnome.org/Apps/PdfMod
COMMENT=	PDF Mod is a simple tool for modifying PDF documents
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config intltool msgfmt gmake
USE_LANGUAGES=		c c++
REPLACE_SH=		icon-theme-installer

INSTALLATION_DIRS+=	lib/pdfmod

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/hyena/buildlink3.mk"
# gnome-sharp not needed, but gconf-sharp
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
