# $NetBSD: Makefile,v 1.9 2011/10/29 06:31:21 obache Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
