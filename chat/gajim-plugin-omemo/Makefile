# $NetBSD: Makefile,v 1.2 2018/09/20 00:23:12 nia Exp $

PKGNAME=	gajim-plugin-omemo-2.6.1
DISTNAME=	omemo_${PKGVERSION_NOREV}
PKGREVISION=	1
CATEGORIES=	chat security python
MASTER_SITES=	https://ftp.gajim.org/plugins_releases/
EXTRACT_SUFX=	.zip

MAINTAINER=	nia@NetBSD.org
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
INSTALLATION_DIRS+=	${PYSITELIB}/gajim/data/plugins/omemo/omemo

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.py ${WRKSRC}/*.ui \
	    ${WRKSRC}/*.png ${WRKSRC}/*.ini \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/gajim/data/plugins/omemo
	${INSTALL_DATA} ${WRKSRC}/omemo/* \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/gajim/data/plugins/omemo/omemo

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
