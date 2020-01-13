# $NetBSD: Makefile,v 1.1 2020/01/13 20:39:29 schmonz Exp $

DISTNAME=		pius-3.0.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		security python
MASTER_SITES=		${MASTER_SITE_GITHUB:=jaymzh/pius/releases/download/v3.0.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/jaymzh/pius/
COMMENT=		PGP Individual User Signer
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	setup.py
SUBST_VARS.paths=	PKGMANDIR

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
