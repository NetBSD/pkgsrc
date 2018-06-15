# $NetBSD: Makefile,v 1.43 2018/06/15 08:26:27 adam Exp $

DISTNAME=	fonttools-3.27.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	fonts python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FontTools/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fonttools/fonttools
COMMENT=	Library for manipulating fonts
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.
SUBST_FILES.man+=	setup.py
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in fonttools pyftinspect pyftmerge pyftsubset ttx; do \
		${MV} $${i} $${i}${PYVERSSUFFIX}; \
	done
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
		${MV} ttx.1 ttx${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
