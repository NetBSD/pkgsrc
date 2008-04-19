# $NetBSD: Makefile,v 1.16 2008/04/19 05:43:26 obache Exp $

DISTNAME=	kakasi-2.3.4
PKGREVISION=	4
CATEGORIES=	japanese textproc
MASTER_SITES=	http://kakasi.namazu.org/stable/ \
		ftp://kakasi.namazu.org/pub/kakasi/stable/

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
