# $NetBSD: Makefile,v 1.8 2025/01/17 19:29:03 adam Exp $

DISTNAME=	python_bugzilla-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-bugzilla/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-bugzilla/python-bugzilla
COMMENT=	Bugzilla XMLRPC access module
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses

USE_LANGUAGES=	# none

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Setting correct mandir.
SUBST_FILES.mandir=	setup.py
SUBST_SED.mandir=	-e 's,share/man,${PKGMANDIR},g'

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/bugzilla bin/bugzilla-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/bugzilla.1 ${PKGMANDIR}/man1/bugzilla-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
