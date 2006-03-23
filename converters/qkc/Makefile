# $NetBSD: Makefile,v 1.8 2006/03/23 03:10:25 jlam Exp $

DISTNAME=	qkcc100
PKGNAME=	qkc-1.0
PKGREVISION=	1
CATEGORIES=	japanese converters
MASTER_SITES=	http://hp.vector.co.jp/authors/VA000501/
EXTRACT_SUFX=	.zip

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://hp.vector.co.jp/authors/VA000501/
COMMENT=	Quick Kanji code Converter

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.EUC/man1

WRKSRC=		${WRKDIR}
BUILD_TARGET=	qkc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 ${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1

.include "../../mk/bsd.pkg.mk"
