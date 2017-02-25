# $NetBSD: Makefile,v 1.1 2017/02/25 17:38:41 wiz Exp $

DISTNAME=	py3dns-3.1.1a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py3dns/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/py3dns
COMMENT=	Python 3 DNS library
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	27
WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}
EGG_NAME=	${DISTNAME:S/a$//}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
