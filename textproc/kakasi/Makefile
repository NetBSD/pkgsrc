# $NetBSD: Makefile,v 1.9 2005/03/24 21:13:02 wiz Exp $

DISTNAME=	kakasi-2.3.4
PKGREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://kakasi.namazu.org/pub/kakasi/stable/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://kakasi.namazu.org/
COMMENT=	Kanji-Kana Simple Inverter, language filter for Japanese

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.1 ${PREFIX}/man/ja_JP.EUC/man1
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.cat \
		${PREFIX}/man/ja_JP.EUC/cat1/kakasi.0

.include "../../mk/bsd.pkg.mk"
