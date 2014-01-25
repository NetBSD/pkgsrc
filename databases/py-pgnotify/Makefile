# $NetBSD: Makefile,v 1.16 2014/01/25 10:29:59 wiz Exp $

DISTNAME=	pgnotify-0.1
PKGNAME=	${PYPKGPREFIX}-pgnotify-0.1
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://sandbox.rulemaker.net/ngps/Dist/
EXTRACT_SUFX=	.zip

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://sandbox.rulemaker.net/ngps/pgnotify
COMMENT=	Python interface to PostgreSQL LISTEN/NOTIFY

DEPENDS+=	${PYPKGPREFIX}-postgresql-[0-9]*:../../databases/py-postgresql

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-postgresql

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
