# $NetBSD: Makefile,v 1.7 2019/04/09 10:53:29 adam Exp $

DISTNAME=	scp-0.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbardin/scp.py
COMMENT=	Send and receive files with scp
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
