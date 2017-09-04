# $NetBSD: Makefile,v 1.15 2017/09/04 18:00:56 wiz Exp $

DISTNAME=	skkfep0.86c
PKGNAME=	skkfep-0.86c
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	# ftp://ei5nazha.yz.yamagata-u.ac.jp/skkfep/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://ei5nazha.yz.yamagata-u.ac.jp/~aito/aito-soft.html
COMMENT=	Terminal based SKK-like Kana-to-Kanji FrontEnd Processor

BUILD_DEFS+=	IPV6_READY

WRKSRC=		${WRKDIR}/skkfep
NO_CONFIGURE=	yes
MAKE_ENV+=	MAKE_FLAGS=EXECBASE=${LOCALBASE:Q}\ CC=${CC:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CONF_FILES+=	${PREFIX}/share/examples/skk/skk.conf ${PKG_SYSCONFDIR}/skk.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${DESTDIR}${PREFIX}/bin/skkfep
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/skkfep.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/skk
	${INSTALL_DATA} ${FILESDIR}/skk.conf \
		${DESTDIR}${PREFIX}/share/examples/skk/skk.conf

.include "../../mk/bsd.pkg.mk"
