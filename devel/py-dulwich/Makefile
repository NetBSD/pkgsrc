# $NetBSD: Makefile,v 1.11 2015/04/02 15:28:25 wiz Exp $

DISTNAME=	dulwich-0.10.1a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/d/dulwich/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.samba.org/~jelmer/dulwich/
COMMENT=	Python implementation of Git
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.9.4

# due to trailing 'a'
EGG_NAME=	${DISTNAME}0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
