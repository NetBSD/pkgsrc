# $NetBSD: Makefile,v 1.68 2018/11/12 03:51:50 ryoon Exp $

DISTNAME=		gramps-3.4.4
PKGREVISION=		12
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gramps/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gramps-project.org/
COMMENT=		Genealogical Research and Analysis Management Programming System V3
LICENSE=		gnu-gpl-v2

#DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

USE_TOOLS+=		msgfmt pkg-config intltool msgconv
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2

REPLACE_PYTHON=		src/DateHandler/_Date_fr.py
REPLACE_PYTHON+=	src/plugins/quickview/Reporef.py
REPLACE_PYTHON+=	src/plugins/rel/rel_fr.py
REPLACE_PYTHON+=	src/PlaceUtils.py
REPLACE_PYTHON+=	src/plugins/gramplet/MetadataViewer.py
REPLACE_PYTHON+=	src/plugins/lib/libhtml.py
REPLACE_PYTHON+=	src/plugins/lib/libmetadata.py
REPLACE_PYTHON+=	src/plugins/webreport/WebCal.py

# pkgsrc registers mime files using mimedb.mk (see below)
CONFIGURE_ARGS+=	--enable-packager-mode

# needs svg pixbuf loader at runtime
DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg

.include "options.mk"

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.10
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
