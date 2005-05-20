# $NetBSD: Makefile,v 1.1 2005/05/20 18:10:54 augustss Exp $
#

DISTNAME=	python-mcrypt-1.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-mcrypt/}

MAINTAINER=	augustss@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-mcrypt/
COMMENT=	Python interface to mcrypt library

PYBINMODULE=    yes
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
