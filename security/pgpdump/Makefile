# $NetBSD: Makefile,v 1.14 2004/01/23 14:49:35 taca Exp $
#

DISTNAME=	pgpdump-0.22
CATEGORIES=	security
MASTER_SITES=	ftp://pgp.iijlab.net/pub/pgp/tools/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	ftp://pgp.iijlab.net/pub/pgp/tools/
COMMENT=	PGP packet visualizer

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pgpdump
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README \
		${PREFIX}/share/doc/pgpdump

.include "../../mk/bsd.pkg.mk"
