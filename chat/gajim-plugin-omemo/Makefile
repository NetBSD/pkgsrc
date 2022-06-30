# $NetBSD: Makefile,v 1.12 2022/06/30 11:18:05 nia Exp $

#
# Don't update this package without testing the plugin with Gajim.
#
# The plugin must be fixed a specific version so it works with whatever
# version of Gajim is currently in pkgsrc.
# 
# Please make sure the package version is in sync with the version
# marked "available" in the Gajim plugins menu.
#
PKGNAME=	gajim-plugin-omemo-2.7.14
PKGREVISION=	1
DISTNAME=	omemo_${PKGVERSION_NOREV}
CATEGORIES=	chat security python
MASTER_SITES=	https://ftp.gajim.org/plugins_releases/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.gajim.org/gajim/gajim-plugins/wikis/OmemoGajimPlugin
COMMENT=	OMEMO encryption support for Gajim
LICENSE=	gnu-gpl-v3

DEPENDS+=	gajim-[0-9]*:../../chat/gajim
DEPENDS+=	${PYPKGPREFIX}-axolotl-[0-9]*:../../chat/py-axolotl
DEPENDS+=	${PYPKGPREFIX}-qrcode-[0-9]*:../../graphics/py-qrcode

PYTHON_VERSIONS_INCOMPATIBLE=	27

WRKSRC=		${WRKDIR}/omemo
USE_LANGUAGES=	# none
NO_BUILD=	yes
PY_PATCHPLIST=	yes

INSTALLATION_DIRS+=	${PYSITELIB}/gajim/data/plugins/omemo
INSTALLATION_DIRS+=	${PYSITELIB}/gajim/data/plugins/omemo/backend
INSTALLATION_DIRS+=	${PYSITELIB}/gajim/data/plugins/omemo/gtk
INSTALLATION_DIRS+=	${PYSITELIB}/gajim/data/plugins/omemo/modules

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.py ${WRKSRC}/*.png ${WRKSRC}/*.ini \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/gajim/data/plugins/omemo
	${INSTALL_DATA} ${WRKSRC}/backend/* \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/gajim/data/plugins/omemo/backend
	${INSTALL_DATA} ${WRKSRC}/gtk/*.ui ${WRKSRC}/gtk/*.css ${WRKSRC}/gtk/*.py \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/gajim/data/plugins/omemo/gtk
	${INSTALL_DATA} ${WRKSRC}/modules/* \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/gajim/data/plugins/omemo/modules

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
