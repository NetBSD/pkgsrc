# $NetBSD: Makefile,v 1.11 2003/05/20 16:40:13 yyamano Exp $
#

DISTNAME=	pgpdump-0.18
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
