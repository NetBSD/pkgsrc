# $NetBSD: Makefile,v 1.61 2020/04/11 07:21:37 adam Exp $

DISTNAME=	fonttools-4.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	fonts python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FontTools/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fonttools/fonttools
COMMENT=	Library for manipulating fonts
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
TEST_DEPENDS+=	${PYPKGPREFIX}-fs-[0-9]*:../../filesystems/py-fs
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27 # since 4.0.0

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.
SUBST_FILES.man+=	setup.py
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in fonttools pyftmerge pyftsubset ttx; do \
		${MV} $${i} $${i}-${PYVERSSUFFIX}; \
	done
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
		${MV} ttx.1 ttx-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
