# $NetBSD: Makefile,v 1.5 2003/12/07 00:53:28 epg Exp $
#

DISTNAME=	bsddb3-4.1.1
PKGNAME=	${PYPKGPREFIX}-bsddb3-4.1.1
PKGREVISION= 	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pybsddb/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pybsddb.sourceforge.net/
COMMENT=	Python extension module for Berkeley DB 3 and 4

PYSETUPBUILDARGS=	--berkeley-db=${LOCALBASE}
PYSETUPINSTALLARGS=	--berkeley-db=${LOCALBASE}

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

BUILDLINK_DEPENDS.db4=		db4>=4.2.52

.include "../../databases/db4/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
