# $NetBSD: Makefile,v 1.8 2006/06/07 16:55:34 joerg Exp $
#

DISTNAME=	pgnotify-0.1
PKGNAME=	${PYPKGPREFIX}-pgnotify-0.1
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://sandbox.rulemaker.net/ngps/Dist/
EXTRACT_SUFX=	.zip

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://sandbox.rulemaker.net/ngps/pgnotify
COMMENT=	Python interface to PostgreSQL LISTEN/NOTIFY

DEPENDS+=	${PYPKGPREFIX}-postgresql-[0-9]*:../../databases/py-postgresql

MAKE_ENV+=		MANDIR=${PREFIX}/man
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
