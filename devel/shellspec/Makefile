# $NetBSD: Makefile,v 1.1 2023/02/14 21:26:29 schmonz Exp $

DISTNAME=		shellspec-0.28.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=shellspec/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/shellspec/shellspec/
COMMENT=		Full-featured BDD unit testing for POSIX shells
LICENSE=		mit

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	Makefile
SUBST_VARS.paths=	PREFIX DESTDIR

NO_BUILD=		yes
INSTALL_ENV+=		PREFIX=${DESTDIR:Q}${PREFIX:Q}
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
