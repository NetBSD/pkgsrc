# $NetBSD: Makefile,v 1.2 2003/06/02 01:21:02 jschauma Exp $
#

DISTNAME=	bsddb3-4.1.1
PKGNAME=	${PYPKGPREFIX}-bsddb3-4.1.1
PKGREVISION= 	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pybsddb/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://pybsddb.sourceforge.net/
COMMENT=	Python extension module for Berkeley DB 3 and 4

PYSETUPBUILDARGS=	--berkeley-db=${LOCALBASE}
PYSETUPINSTALLARGS=	--berkeley-db=${LOCALBASE}

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../databases/db4/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
