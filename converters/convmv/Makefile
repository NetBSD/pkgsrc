# $NetBSD: Makefile,v 1.5 2006/07/17 15:09:59 rillig Exp $

DISTNAME=		convmv-1.09
CATEGORIES=		converters
MASTER_SITES=		http://www.j3e.de/linux/convmv/

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://j3e.de/linux/convmv/
COMMENT=		Converts filenames from one encoding to another

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl:run

MANCOMPRESSED=		yes
NO_BUILD=		yes

BUILD_DEFS+=		GNU_PROGRAM_PREFIX

# the test script needs the GNU versions
MAKE_ENV+=		CONVMV_LS=${GNU_PROGRAM_PREFIX}ls \
			CONVMV_CP=${GNU_PROGRAM_PREFIX}cp

MAKEFLAGS+=		MANDIR=${PREFIX}/man \
			INSTALL_MAN_DIR=${INSTALL_MAN_DIR:Q} \
			INSTALL_SCRIPT_DIR=${INSTALL_SCRIPT_DIR:Q} \
			INSTALL_MAN=${INSTALL_MAN:Q} \
			INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}

REPLACE_PERL+=		${WRKSRC}/convmv

SUBST_CLASSES+=		convmv
SUBST_STAGE.convmv=	pre-configure
SUBST_FILES.convmv=	suite/dotests.sh
SUBST_SED.convmv=	-e "1s|/bin/sh|${SH}|"

TEST_TARGET=		test

post-extract:
	# use option p to get the right permissions for symlinks
	cd ${WRKSRC} && ${TAR} -xpf testsuite.tar

.include "../../mk/bsd.pkg.mk"
