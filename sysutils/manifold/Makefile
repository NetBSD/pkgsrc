# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:19 wiz Exp $

PKGNAME=	${DISTNAME:S/^M/m/}
DISTNAME=	Manifold-0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://pypi.python.org/packages/source/M/Manifold/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://code.google.com/p/manifold/
COMMENT=	SMF service manifest creation tool
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-genshi-[0-9]*:../../www/py-genshi

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=  33 34 # not yet ported as of 0.2.0

post-extract:
	${CHMOD} -R g-w ${WRKSRC}/*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
