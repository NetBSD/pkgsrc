# $NetBSD: Makefile,v 1.10 2012/10/23 18:16:54 asau Exp $
#

DISTNAME=	python-mcrypt-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://labix.org/download/python-mcrypt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labix.org/python-mcrypt
COMMENT=	Python interface to mcrypt library
LICENSE=	gnu-lgpl-v2.1

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
