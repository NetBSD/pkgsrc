# $NetBSD: Makefile,v 1.7 2006/10/04 20:55:14 wiz Exp $
#

DISTNAME=		bzr-0.11
CATEGORIES=		devel
MASTER_SITES=		http://bazaar-vcs.org/releases/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bazaar-vcs.org/
COMMENT=		Open source distributed version control system

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
