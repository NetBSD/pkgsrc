# $NetBSD: Makefile,v 1.8 2006/02/18 22:08:50 wiz Exp $

DISTNAME=	skkfep0.86c
PKGNAME=	skkfep-0.86c
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ei5nazha.yz.yamagata-u.ac.jp/skkfep/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ei5nazha.yz.yamagata-u.ac.jp/~aito/aito-soft.html
COMMENT=	Terminal based SKK-like Kana-to-Kanji FrontEnd Processor

BUILD_DEFS+=	USE_INET6

WRKSRC=		${WRKDIR}/skkfep
NO_CONFIGURE=	yes
MAKE_ENV+=	MAKE_FLAGS=EXECBASE=${LOCALBASE:Q}\ CC=${CC:Q}

INSTALLATION_DIRS=	bin man/man1

CONF_FILES+=	${PREFIX}/share/examples/skk/skk.conf ${PKG_SYSCONFDIR}/skk.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${PREFIX}/bin/skkfep
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 ${PREFIX}/man/man1/skkfep.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/skk
	${INSTALL_DATA} ${FILESDIR}/skk.conf ${PREFIX}/share/examples/skk/skk.conf

.include "../../mk/bsd.pkg.mk"
