# $NetBSD: Makefile,v 1.1 2013/09/13 08:51:09 fhajny Exp $
#

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

PYDISTUTILSPKG=	yes

post-extract:
	${CHMOD} -R g-w ${WRKSRC}/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
