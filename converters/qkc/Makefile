# $NetBSD: Makefile,v 1.5 2004/12/03 15:14:52 wiz Exp $
# FreeBSD: ports/japanese/qkc/Makefile,v 1.15 2001/05/10 11:42:23 max Exp

DISTNAME=	qkcc100
PKGNAME=	qkc-1.0
CATEGORIES=	japanese converters
MASTER_SITES=	http://hp.vector.co.jp/authors/VA000501/
EXTRACT_SUFX=	.zip

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://hp.vector.co.jp/authors/VA000501/
COMMENT=	Quick Kanji code Converter

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin man/ja_JP.EUC/man1

WRKSRC=		${WRKDIR}
BUILD_TARGET=	qkc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 ${PREFIX}/man/ja_JP.EUC/man1

.include "../../mk/bsd.pkg.mk"
