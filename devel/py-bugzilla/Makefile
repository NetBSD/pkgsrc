# $NetBSD: Makefile,v 1.6 2022/07/08 14:01:33 wiz Exp $

DISTNAME=	python-bugzilla-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-bugzilla/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-bugzilla/python-bugzilla
COMMENT=	Bugzilla XMLRPC access module
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Setting correct mandir.
SUBST_FILES.mandir=	setup.py
SUBST_SED.mandir=	-e 's,share/man,${PKGMANDIR},g'

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/bugzilla bin/bugzilla-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/bugzilla.1 ${PKGMANDIR}/man1/bugzilla-${PYVERSSUFFIX}.1 || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
