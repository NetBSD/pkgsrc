# $NetBSD: Makefile,v 1.6 2008/04/25 20:39:12 joerg Exp $
#

DISTNAME=	python-mcrypt-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-mcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-mcrypt/
COMMENT=	Python interface to mcrypt library

PYBINMODULE=	yes
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
