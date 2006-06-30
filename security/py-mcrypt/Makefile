# $NetBSD: Makefile,v 1.3 2006/06/30 11:37:56 joerg Exp $
#

DISTNAME=	python-mcrypt-1.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-mcrypt/}

MAINTAINER=	augustss@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-mcrypt/
COMMENT=	Python interface to mcrypt library

PYBINMODULE=    yes
PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
