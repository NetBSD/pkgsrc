# $NetBSD: Makefile,v 1.19 2007/09/24 03:57:59 taca Exp $
#

DISTNAME=	pgpdump-0.26
CATEGORIES=	security
MASTER_SITES=	http://pgp.iijlab.net/pgpdump/ \
		http://www.mew.org/~kazu/proj/pgpdump/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://pgp.iijlab.net/pgpdump.html
COMMENT=	PGP packet visualizer

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pgpdump
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/pgpdump

.include "../../mk/bsd.pkg.mk"
