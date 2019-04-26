# $NetBSD: Makefile,v 1.22 2019/04/26 13:13:57 maya Exp $

DISTNAME=		TTFQuery-1.0.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_PYPI:=T/TTFQuery/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ttfquery.sourceforge.net/
COMMENT=		Query TTF font files for metadata and font outlines
LICENSE=		modified-bsd

DEPENDS+=		${PYPKGPREFIX}-fonttools>=2.0b1:../../fonts/py-fonttools

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-fonttools

post-install:
	cd ${DESTDIR}${PREFIX}/bin && for f in ttffamily ttffiles ttfgroups ttfmetadata; do \
		${MV} $${f} $${f}${PYVERSSUFFIX}; \
	done

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
