# $NetBSD: Makefile,v 1.1 2017/06/07 09:43:15 he Exp $

DISTNAME=	scp-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbardin/scp.py
COMMENT=	Send and receive files with scp
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}
PYTHON_VERSIONS_ACCEPTED=	27

PYDISTUTILSPKG= yes

DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
