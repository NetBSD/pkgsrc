# $NetBSD: Makefile,v 1.1 2017/09/29 14:31:29 joerg Exp $

DISTNAME=	txgithub-15.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txgithub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomprince/txgithub
COMMENT=	GitHub API client using Twisted
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
