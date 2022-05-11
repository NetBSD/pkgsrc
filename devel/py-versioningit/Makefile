# $NetBSD: Makefile,v 1.1 2022/05/11 17:51:43 bouyer Exp $

DISTNAME=	versioningit-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/versioningit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jwodder/versioningit
COMMENT=	Use version control tags to discover version numbers
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wheel>=0.32:../../devel/py-wheel

post-extract: setuppy
.PHONY: setuppy
setuppy:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
