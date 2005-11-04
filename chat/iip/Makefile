# $NetBSD: Makefile,v 1.1.1.1 2005/11/04 08:53:54 rillig Exp $
#

DISTNAME=		iip-1.1.0
CATEGORIES=		chat security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=invisibleip/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.invisiblenet.net/iip/
COMMENT=		The Invisible IRC Project

BUILD_DIRS=		${WRKSRC}/src
MAKE_FLAGS+=		CC=${CC:Q} LD=${CC:Q} LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}" "${CPPFLAGS:Q}" -I."

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/isproxy ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/iip
	${INSTALL_DATA} ${WRKSRC}/src/node.ref ${PREFIX}/share/examples/iip/
	${INSTALL_DATA} ${WRKSRC}/doc/isproxy.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
