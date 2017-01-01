# $NetBSD: Makefile,v 1.16 2017/01/01 14:43:55 wiz Exp $

DISTNAME=	python-mcrypt-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://labix.org/download/python-mcrypt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labix.org/python-mcrypt
COMMENT=	Python interface to mcrypt library
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.1

.include "../../lang/python/distutils.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
