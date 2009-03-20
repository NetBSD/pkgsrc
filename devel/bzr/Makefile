# $NetBSD: Makefile,v 1.36 2009/03/20 06:49:10 epg Exp $

DISTNAME=		bzr-${VER}
#PKGREVISION=		1
CATEGORIES=		devel scm
MASTER_SITES=		http://launchpad.net/bzr/${VER}/${VER}/+download/
VER=			1.13

MAINTAINER=		epg@NetBSD.org
HOMEPAGE=		http://bazaar-vcs.org/
COMMENT=		Bazaar open source distributed version control system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-expat>=0:../../textproc/py-expat
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

USE_TOOLS+=		gmake

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	25 24
PYTHON_PATCH_SCRIPTS=		bzr bzrlib/weave.py

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
DEPENDS+=		${PYPKGPREFIX}-medusa>=0:../../net/py-medusa
.endif

SUBST_CLASSES+=			python
SUBST_MESSAGE.python=		Fix python path for test case.
SUBST_STAGE.python=		post-extract
SUBST_FILES.python+=		Makefile
SUBST_SED.python+=		-e 's,=python,=${PYTHONBIN},'

post-build:
	cd ${WRKSRC} && ${PYTHONBIN} generate_docs.py man

do-test:
#	XXX shouldn't HOME=FAKEHOME already be set?
	HOME=${FAKEHOMEDIR}; cd ${WRKSRC} && ./bzr selftest -v

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
