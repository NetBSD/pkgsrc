# $NetBSD: Makefile,v 1.1.1.1 2004/10/21 16:03:37 darcy Exp $
#

DISTNAME=	pgnotify-0.1
PKGNAME=	${PYPKGPREFIX}-pgnotify-0.1
CATEGORIES=	databases python
MASTER_SITES=	http://sandbox.rulemaker.net/ngps/Dist/
EXTRACT_SUFX=	.zip

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://sandbox.rulemaker.net/ngps/pgnotify
COMMENT=	Python interface to PostgreSQL LISTEN/NOTIFY

DEPENDS+=	${PYPKGPREFIX}-postgresql*:../../databases/py-postgresql

MAKE_ENV+=		MANDIR=${PREFIX}/man
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
