# $NetBSD: Makefile,v 1.13 2001/11/26 06:22:02 jlam Exp $
# FreeBSD Id: Makefile,v 1.14 1998/04/05 04:46:33 max Exp $

DISTNAME=	kakasi-2.3.4
CATEGORIES=	japanese
MASTER_SITES=	ftp://kakasi.namazu.org/pub/kakasi/stable/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://kakasi.namazu.org/
COMMENT=	Kanji-Kana Simple Inverter, language filter for Japanese

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.1 ${PREFIX}/man/ja_JP.EUC/man1
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.cat \
		${PREFIX}/man/ja_JP.EUC/cat1/kakasi.0

.include "../../mk/bsd.pkg.mk"
