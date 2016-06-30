# $NetBSD: Makefile,v 1.25 2016/06/30 17:56:14 wiz Exp $

DISTNAME=	fonttools-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=behdad/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/behdad/fonttools/
COMMENT=	Library for manipulating fonts

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
USE_LANGUAGES=	# none

REPLACE_PYTHON+=	setup.py

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in pyftinspect pyftmerge pyftsubset ttx; do \
		mv $$i $$i-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
