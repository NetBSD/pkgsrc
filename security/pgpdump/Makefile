# $NetBSD: Makefile,v 1.17 2005/10/13 17:29:32 wiz Exp $
#

DISTNAME=	pgpdump-0.24
CATEGORIES=	security
MASTER_SITES=	http://pgp.iijlab.net/pgpdump/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://pgp.iijlab.net/pgpdump.html
COMMENT=	PGP packet visualizer

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pgpdump
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README \
		${PREFIX}/share/doc/pgpdump

.include "../../mk/bsd.pkg.mk"
