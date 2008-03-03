# $NetBSD: Makefile,v 1.7 2008/03/03 02:19:51 jlam Exp $
#

DISTNAME=		iip-1.1.0
CATEGORIES=		chat security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=invisibleip/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.invisiblenet.net/iip/
COMMENT=		The Invisible IRC Project

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=		src
MAKE_FLAGS+=		CC=${CC:Q}
MAKE_FLAGS+=		LD=${CC:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:M*:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:M*:Q}\ ${CPPFLAGS:M*:Q}\ -I.

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/isproxy ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/iip
	${INSTALL_DATA} ${WRKSRC}/src/node.ref \
		${DESTDIR}${PREFIX}/share/examples/iip/
	${INSTALL_DATA} ${WRKSRC}/doc/isproxy.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
