# $NetBSD: Makefile,v 1.22 2012/10/23 18:16:49 asau Exp $
#

DISTNAME=	pgpdump-0.26
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.mew.org/~kazu/proj/pgpdump/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://pgp.iijlab.net/pgpdump.html
COMMENT=	PGP packet visualizer

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pgpdump
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/pgpdump

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
