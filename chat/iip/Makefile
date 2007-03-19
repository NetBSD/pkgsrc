# $NetBSD: Makefile,v 1.6 2007/03/19 16:40:26 tv Exp $
#

DISTNAME=		iip-1.1.0
CATEGORIES=		chat security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=invisibleip/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.invisiblenet.net/iip/
COMMENT=		The Invisible IRC Project

BUILD_DIRS=		src
MAKE_FLAGS+=		CC=${CC:Q}
MAKE_FLAGS+=		LD=${CC:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:M*:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:M*:Q}\ ${CPPFLAGS:M*:Q}\ -I.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/isproxy ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/iip
	${INSTALL_DATA} ${WRKSRC}/src/node.ref ${PREFIX}/share/examples/iip/
	${INSTALL_DATA} ${WRKSRC}/doc/isproxy.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
