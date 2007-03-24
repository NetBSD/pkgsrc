# $NetBSD: Makefile,v 1.15 2007/03/24 19:21:32 joerg Exp $

DISTNAME=	kakasi-2.3.4
PKGREVISION=	4
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://kakasi.namazu.org/pub/kakasi/stable/

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
