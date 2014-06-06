# $NetBSD: Makefile,v 1.22 2014/06/06 12:09:47 obache Exp $

DISTNAME=	kakasi-2.3.6
CATEGORIES=	japanese textproc
MASTER_SITES=	http://kakasi.namazu.org/stable/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://kakasi.namazu.org/
COMMENT=	Kanji-Kana Simple Inverter, language filter for Japanese
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
INSTALLATION_DIRS=	${PKGMANDIR}/ja_JP.EUC/man1

TEST_TARGET=		check

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/kakasi.1.ja ${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/kakasi.1

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
