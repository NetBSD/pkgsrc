# $NetBSD: Makefile,v 1.4 2013/04/06 13:09:25 rodent Exp $
#

DISTNAME=		ether2dns-1.6
CATEGORIES=		net
MASTER_SITES=		http://theory.cs.uni-bonn.de/~ignatios/
EXTRACT_SUFX=		.shar

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://theory.cs.uni-bonn.de/~ignatios/
COMMENT=		Converter from /etc/ethers to IPv6 DNS records

WRKSRC=			${WRKDIR}

USE_TOOLS+=		lex
USE_LANGUAGES=		c

MAKE_FILE=		Makefile.notbsd
MAKE_FLAGS+=		CC=${CC:Q}
MAKE_FLAGS+=		LEX=${LEX:Q}

BUILD_TARGET=		ether2dns
TEST_TARGET=		test

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/ether2dns ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ether2dns/
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/ether2dns/

.include "../../mk/bsd.pkg.mk"
