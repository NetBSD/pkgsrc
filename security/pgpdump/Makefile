# $NetBSD: Makefile,v 1.1.1.1 2001/03/28 09:04:21 jun Exp $
#

DISTNAME=	pgpdump-0.05
CATEGORIES=	security
MASTER_SITES=	ftp://pgp.iijlab.net/pub/pgp/tools/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	ftp://pgp.iijlab.net/pub/pgp/tools/
COMMENT=	PGP packet visualizer

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pgpdump
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README \
		${PREFIX}/share/doc/pgpdump

.include "../../mk/bsd.pkg.mk"
