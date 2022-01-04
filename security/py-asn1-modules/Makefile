# $NetBSD: Makefile,v 1.13 2022/01/04 20:54:37 wiz Exp $

DISTNAME=	pyasn1-modules-0.2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	security python
#MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyasn1-modules/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=etingof/}
GITHUB_PROJECT=	pyasn1-modules
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/etingof/pyasn1-modules
COMMENT=	Modules for ITU Abstract Syntax Notification for Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.4.1:../../security/py-asn1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
