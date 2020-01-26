# $NetBSD: Makefile,v 1.12 2020/01/26 17:30:52 rillig Exp $

DISTNAME=	qkcc100
PKGNAME=	qkc-1.0
PKGREVISION=	1
CATEGORIES=	japanese converters
MASTER_SITES=	http://hp.vector.co.jp/authors/VA000501/
EXTRACT_SUFX=	.zip

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://hp.vector.co.jp/authors/VA000501/
COMMENT=	Quick Kanji code Converter

INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.EUC/man1

WRKSRC=		${WRKDIR}
BUILD_TARGET=	qkc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1

.include "../../mk/bsd.pkg.mk"
