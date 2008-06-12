# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:45 joerg Exp $
#

DISTNAME=	python-mcrypt-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-mcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-mcrypt/
COMMENT=	Python interface to mcrypt library

PKG_DESTDIR_SUPPORT=	user-destdir

PYBINMODULE=	yes
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
