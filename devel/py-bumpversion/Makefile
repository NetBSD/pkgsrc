# $NetBSD: Makefile,v 1.1 2020/09/28 23:14:47 khorben Exp $

DISTNAME=	bumpversion-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=peritus/}
GITHUB_PROJECT=	bumpversion
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/peritus/bumpversion
COMMENT=	Version-bump your software with a single command!
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/bumpversion ${DESTDIR}${PREFIX}/bin/bumpversion-${PYVERSSUFFIX} || ${TRUE}

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
