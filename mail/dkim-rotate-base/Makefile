#	$NetBSD: Makefile,v 1.1 2026/10/14 03:34:55 riastradh Exp $
#

.include "../../mail/dkim-rotate/Makefile.common"

PKGNAME=	${DISTNAME:C/^dkim-rotate-dkim-rotate-/dkim-rotate-base-/}

COMMENT=	Tool for rotation and revocation of DKIM keys

USE_LANGUAGES=	# none

USE_TOOLS+=	perl:run

DEPENDS+=	p5-Getopt-Long-Descriptive>=0:../../devel/p5-Getopt-Long-Descriptive

REPLACE_PERL+=	dkim-rotate

EGDIR=			${PREFIX}/share/examples/dkim-rotate
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${EGDIR}

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/dkim-rotate ${DESTDIR:Q}${PREFIX:Q}/bin/
	${INSTALL_DATA} ${WRKSRC:Q}/example.zone ${WRKSRC:Q}/crontab \
	    ${DESTDIR:Q}${EGDIR:Q}/

USE_TOOLS+=		bash:test date:test ggrep:test gmake:test realpath:test

TOOL_DEPENDS+=		coreutils>=0:../../sysutils/coreutils

TOOLS_PATH.date=	${TOOLBASE}/gnu/bin/date
TOOLS_PATH.grep=	${TOOLBASE}/gnu/bin/grep

TOOLS_CREATE+=		md5sum
TOOLS_PATH.md5sum=	${TOOLBASE}/gnu/bin/md5sum

TOOLS_CREATE+=		base64
TOOLS_SCRIPT.base64=	exec openssl base64 "$$@"

REPLACE_BASH+=		debian/tests/*
REPLACE_BASH+=		tests/*

TEST_TARGET+=		check
TEST_MAKE_FLAGS+=	SHELL=${SHELL:Q}

.include "../../mk/bsd.pkg.mk"
