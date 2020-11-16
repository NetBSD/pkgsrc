# $NetBSD: Makefile,v 1.10 2020/11/16 15:48:43 tsutsui Exp $

DISTNAME=	lhasa-0.3.1
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://soulsphere.org/projects/lhasa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fragglet.github.com/lhasa/
COMMENT=	Freely licensed lha archiving tool (for .lzh and .lha files)
LICENSE=	isc

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	liblhasa.pc.in
TEST_TARGET=		check

USE_TOOLS+=		bash # tests-only
REPLACE_BASH+=		test/test-dry-run
REPLACE_BASH+=		test/test-crc-output
REPLACE_BASH+=		test/test-print
REPLACE_BASH+=		test/test-decompress
REPLACE_BASH+=		test/test-file-headers
REPLACE_BASH+=		test/test-extract
REPLACE_BASH+=		test/test-list-output

.include "../../mk/bsd.pkg.mk"
