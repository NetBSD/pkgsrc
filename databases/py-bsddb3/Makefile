# $NetBSD: Makefile,v 1.6 2004/02/10 17:56:55 minskim Exp $
#

DISTNAME=	bsddb3-4.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pybsddb/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pybsddb.sourceforge.net/
COMMENT=	Python extension module for Berkeley DB 4

PYSETUPBUILDARGS=	--berkeley-db=${LOCALBASE}
PYSETUPINSTALLARGS=	--berkeley-db=${LOCALBASE}

USE_BUILDLINK3=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

BUILDLINK_DEPENDS.db4+=		db4>=4.2.52

.include "../../databases/db4/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
