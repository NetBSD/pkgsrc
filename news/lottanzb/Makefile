# $NetBSD: Makefile,v 1.16 2011/11/24 13:38:15 joerg Exp $

DISTNAME=	lottanzb-0.4.0
PKGREVISION=	11
CATEGORIES=	news
MASTER_SITES=	http://www.lottanzb.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lottanzb.org/
COMMENT=	GNOME front-end for HellaNZB

DIST_SUBDIR=	lottanzb

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=          yes
PYDISTUTILSPKG=         yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt pkg-config

PYTHON_VERSIONS_ACCEPTED=	27 26 25
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c6:../../devel/py-setuptools
INSTALLATION_DIRS+=	${PYSITELIB}

REPLACE_PYTHON=	lottanzb/postprocessor.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/py-kiwi/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
