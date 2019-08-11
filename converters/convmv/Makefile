# $NetBSD: Makefile,v 1.29 2019/08/11 13:18:10 wiz Exp $

DISTNAME=		convmv-2.05
PKGREVISION=		2
CATEGORIES=		converters
MASTER_SITES=		https://www.j3e.de/linux/convmv/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://j3e.de/linux/convmv/
COMMENT=		Converts filenames from one encoding to another
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# empty
USE_TOOLS+=		pax perl:run

MANCOMPRESSED=		yes
NO_BUILD=		yes

MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		INSTALL_MAN_DIR=${INSTALL_MAN_DIR:Q}
MAKE_FLAGS+=		INSTALL_SCRIPT_DIR=${INSTALL_SCRIPT_DIR:Q}
MAKE_FLAGS+=		INSTALL_MAN=${INSTALL_MAN:Q}
MAKE_FLAGS+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}

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
