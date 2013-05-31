# $NetBSD: Makefile,v 1.17 2013/05/31 12:39:43 wiz Exp $

DISTNAME=		convmv-1.15
PKGREVISION=		2
CATEGORIES=		converters
MASTER_SITES=		http://www.j3e.de/linux/convmv/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://j3e.de/linux/convmv/
COMMENT=		Converts filenames from one encoding to another
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
USE_TOOLS+=		pax perl:run

MANCOMPRESSED=		yes
NO_BUILD=		yes

MAKEFLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKEFLAGS+=		INSTALL_MAN_DIR=${INSTALL_MAN_DIR:Q}
MAKEFLAGS+=		INSTALL_SCRIPT_DIR=${INSTALL_SCRIPT_DIR:Q}
MAKEFLAGS+=		INSTALL_MAN=${INSTALL_MAN:Q}
MAKEFLAGS+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}

REPLACE_PERL+=		${WRKSRC}/convmv
REPLACE_PERL+=		suite/parsable_tester.pl
REPLACE_SH+=		suite/dotests.sh

CHECK_PORTABILITY_SKIP=	suite/test-nfd/*

TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if empty(OPSYS:MDarwin)
post-extract:
	# use option p to get the right permissions for symlinks
	cd ${WRKSRC} && pax -p p -rf testsuite.tar
.endif

.include "../../mk/bsd.pkg.mk"
