# $NetBSD: Makefile,v 1.27 2017/10/02 22:42:47 khorben Exp $

DISTNAME=	fonttools-3.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=fonttools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://groups.google.com/forum/#!forum/fonttools
COMMENT=	Library for manipulating fonts
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in fonttools pyftinspect pyftmerge pyftsubset ttx; do \
		mv $$i $$i-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
