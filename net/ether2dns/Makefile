# $NetBSD: Makefile,v 1.3 2012/10/23 17:18:19 asau Exp $
#

DISTNAME=		ether2dns-1.6
CATEGORIES=		net
MASTER_SITES=		http://theory.cs.uni-bonn.de/~ignatios/
EXTRACT_SUFX=		.shar

MAINTAINER=		is@netbsd.org
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
