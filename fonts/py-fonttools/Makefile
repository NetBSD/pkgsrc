# $NetBSD: Makefile,v 1.34 2017/12/22 06:07:42 adam Exp $

DISTNAME=	fonttools-3.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	fonts python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FontTools/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fonttools/fonttools
COMMENT=	Library for manipulating fonts
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in fonttools pyftinspect pyftmerge pyftsubset ttx; do \
		${MV} $${i} $${i}${PYVERSSUFFIX}; \
	done
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
		${MV} ttx.1 ttx${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
