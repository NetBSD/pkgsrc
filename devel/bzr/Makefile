# $NetBSD: Makefile,v 1.6 2006/08/13 23:47:38 wiz Exp $
#

DISTNAME=		bzr-0.9
CATEGORIES=		devel
MASTER_SITES=		http://www.bazaar-ng.org/pkg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bazaar-ng.org/
COMMENT=		Open source distributed version control system (Bazaar-NG)

DEPENDS+=		${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

PY_PATCHPLIST=          yes
PYDISTUTILSPKG=		yes
TEST_TARGET=		check

PYTHON_VERSIONS_ACCEPTED=	24
PYTHON_PATCH_SCRIPTS=		bzr

post-build:
	cd ${WRKSRC} && ${PYTHONBIN} generate_docs.py man

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bzr
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt  ${PREFIX}/share/doc/bzr

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
