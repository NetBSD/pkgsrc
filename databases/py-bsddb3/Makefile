# $NetBSD: Makefile,v 1.3 2003/06/10 09:56:16 wiz Exp $
#

DISTNAME=	bsddb3-4.1.1
PKGNAME=	${PYPKGPREFIX}-bsddb3-4.1.1
PKGREVISION= 	2
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
