# $NetBSD: Makefile,v 1.6 2020/04/12 08:28:56 adam Exp $

DISTNAME=		greylisting-spp-1.1
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.unix-ag.uni-kl.de/~conrad/greylisting/
COMMENT=		Plugin for qmail-spp that provides greylisting
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake
CONFIGURE_SCRIPT=	${MAKE}
CONFIGURE_ARGS=		${BUILD_MAKE_FLAGS}
BUILD_DIRS=		src
TEST_DIRS=		test
TEST_TARGET=		run-tests

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

.include "options.mk"

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} src/greylisting-spp \
		${DESTDIR}${PREFIX}/bin; \
	for i in README README.db-bdb README.db-file \
		README.db-sqlite README.db-sqlite3 README.dbapi; do \
		${INSTALL_DATA} doc/$$i \
			${DESTDIR}${PREFIX}/share/doc/${PKGBASE}; \
	done

.include "../../mk/bsd.pkg.mk"
