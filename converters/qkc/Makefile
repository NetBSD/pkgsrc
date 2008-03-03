# $NetBSD: Makefile,v 1.9 2008/03/03 05:51:08 jlam Exp $

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
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.EUC/man1

WRKSRC=		${WRKDIR}
BUILD_TARGET=	qkc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1

.include "../../mk/bsd.pkg.mk"
