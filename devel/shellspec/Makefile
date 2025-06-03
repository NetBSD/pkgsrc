# $NetBSD: Makefile,v 1.3 2025/06/03 17:46:55 schmonz Exp $

DISTNAME=		shellspec-0.28.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=shellspec/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://shellspec.info/
COMMENT=		Full-featured BDD unit testing for POSIX shells
LICENSE=		mit

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	Makefile
SUBST_VARS.paths=	PREFIX DESTDIR

NO_BUILD=		yes
USE_TOOLS+=		pax
TEST_TARGET=		test

INSTALLATION_DIRS=	bin lib/shellspec

do-install:
	cd ${WRKSRC} && \
	pax -rw lib ${DESTDIR}${PREFIX}/lib/shellspec/ && \
	pax -rw libexec ${DESTDIR}${PREFIX}/lib/shellspec/ && \
	${INSTALL_SCRIPT} shellspec ${DESTDIR}${PREFIX}/lib/shellspec/ && \
	${INSTALL_DATA} LICENSE ${DESTDIR}${PREFIX}/lib/shellspec/LICENSE && \
	${INSTALL_SCRIPT} stub/shellspec ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
