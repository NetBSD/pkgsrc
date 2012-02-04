# $NetBSD: Makefile,v 1.17 2012/02/04 11:20:34 obache Exp $

DISTNAME=	lottanzb-0.4.1
CATEGORIES=	news
MASTER_SITES=	http://www.lottanzb.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lottanzb.org/
COMMENT=	GNOME front-end for HellaNZB
LICENSE=	gnu-gpl-v3

DEPENDS+=	hellanzb>=0.13:../../news/hellanzb
DEPENDS+=	${PYPKGPREFIX}-kiwi>=1.9.9:../../x11/py-kiwi

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#none
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt

PYTHON_VERSIONS_ACCEPTED=	27 26 25

REPLACE_PYTHON=	lottanzb/postprocessor.py

SUBST_CLASSES+=		localedir
SUBST_STAGE.localedir=	pre-configure
SUBST_FILES.localedir=	setup.py
SUBST_SED.localedir=	-e 's|share/locale|${PKGLOCALEDIR}/locale|'

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
