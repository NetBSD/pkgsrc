# $NetBSD: Makefile,v 1.25 2020/01/26 17:32:06 rillig Exp $
#

DISTNAME=	pgpdump-0.31
CATEGORIES=	security
MASTER_SITES=	http://www.mew.org/~kazu/proj/pgpdump/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	https://www.mew.org/~kazu/proj/pgpdump/en/
COMMENT=	PGP packet visualizer

LICENSE=	modified-bsd

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pgpdump
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/pgpdump

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
