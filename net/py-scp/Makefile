# $NetBSD: Makefile,v 1.2 2017/10/16 11:37:21 adam Exp $

DISTNAME=	scp-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbardin/scp.py
COMMENT=	Send and receive files with scp
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
