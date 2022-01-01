# $NetBSD: Makefile,v 1.21 2022/01/01 15:07:27 wiz Exp $

DISTNAME=	pgnotify-0.1
PKGNAME=	${PYPKGPREFIX}-pgnotify-0.1
PKGREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	http://sandbox.rulemaker.net/ngps/Dist/
EXTRACT_SUFX=	.zip

OWNER=		darcy@NetBSD.org
#HOMEPAGE=	http://sandbox.rulemaker.net/ngps/pgnotify
COMMENT=	Python interface to PostgreSQL LISTEN/NOTIFY

DEPENDS+=	${PYPKGPREFIX}-postgresql-[0-9]*:../../databases/py-postgresql

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
