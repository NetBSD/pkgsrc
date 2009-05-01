# $NetBSD: Makefile,v 1.17 2009/05/01 14:59:30 zafer Exp $

DISTNAME=	kakasi-2.3.4
PKGREVISION=	4
CATEGORIES=	japanese textproc
MASTER_SITES=	http://kakasi.namazu.org/stable/ 

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://kakasi.namazu.org/
COMMENT=	Kanji-Kana Simple Inverter, language filter for Japanese

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
INSTALLATION_DIRS=	${PKGMANDIR}/ja_JP.EUC/cat1 ${PKGMANDIR}/ja_JP.EUC/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.1 ${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.cat \
		${PREFIX}/${PKGMANDIR}/ja_JP.EUC/cat1/kakasi.0

.include "../../mk/bsd.pkg.mk"
