# $NetBSD: Makefile,v 1.8 2014/01/20 12:42:24 wiz Exp $

DISTNAME=	dulwich-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/d/dulwich/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.samba.org/~jelmer/dulwich/
COMMENT=	Python implementation of Git
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.9.4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
