# $NetBSD: Makefile,v 1.34 2022/06/30 11:18:44 nia Exp $

DISTNAME=	lottanzb-0.4.1
PKGREVISION=	5
CATEGORIES=	news
#MASTER_SITES=	http://www.lottanzb.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.lottanzb.org/
COMMENT=	GNOME front-end for HellaNZB
LICENSE=	gnu-gpl-v3

DEPENDS+=	hellanzb>=0.13:../../news/hellanzb
DEPENDS+=	${PYPKGPREFIX}-kiwi>=1.9.9:../../x11/py-kiwi

USE_LANGUAGES=		#none
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt

REPLACE_PYTHON=	lottanzb/postprocessor.py
PYTHON_VERSIONS_ACCEPTED= 27 # py-gtk2 via py-kiwi

SUBST_CLASSES+=		localedir
SUBST_STAGE.localedir=	pre-configure
SUBST_FILES.localedir=	setup.py
SUBST_SED.localedir=	-e 's|share/locale|${PKGLOCALEDIR}/locale|'

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
