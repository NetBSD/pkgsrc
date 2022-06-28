# $NetBSD: Makefile,v 1.9 2022/06/28 11:35:50 wiz Exp $

DISTNAME=		pius-3.0.0
PKGREVISION=		6
CATEGORIES=		security python
MASTER_SITES=		${MASTER_SITE_GITHUB:=jaymzh/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/jaymzh/pius/
COMMENT=		PGP Individual User Signer
LICENSE=		gnu-gpl-v2

DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
DEPENDS+=		gnupg2-[0-9]*:../../security/gnupg2

USE_LANGUAGES=		# none
USE_TOOLS+=		perl:run

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	setup.py pius-keyring-mgr libpius/constants.py
SUBST_FILES.paths+=	doc/pius.1 doc/pius-keyring-mgr.1 doc/pius-report.1
SUBST_VARS.paths=	PREFIX PKGMANDIR

REPLACE_PERL+=		pius-party-worksheet

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
