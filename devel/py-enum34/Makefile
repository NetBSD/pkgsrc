# $NetBSD: Makefile,v 1.13 2022/01/04 20:53:02 wiz Exp $

DISTNAME=	enum34-1.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enum34/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/stoneleaf/enum34
COMMENT=	Python 3.4 Enum backported
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	27 # unnecessary on 34 and newer

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
