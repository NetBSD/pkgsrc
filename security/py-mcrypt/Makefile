# $NetBSD: Makefile,v 1.21 2020/01/26 17:32:07 rillig Exp $

DISTNAME=	python-mcrypt-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://labix.org/download/python-mcrypt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://labix.org/python-mcrypt
COMMENT=	Python interface to mcrypt library
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.1

.include "../../lang/python/distutils.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
