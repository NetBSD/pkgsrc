# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:22 jmmv Exp $
# FreeBSD: ports/japanese/qkc/Makefile,v 1.15 2001/05/10 11:42:23 max Exp

DISTNAME=	qkcc100
PKGNAME=	qkc-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	japanese converters
MASTER_SITES=	http://hp.vector.co.jp/authors/VA000501/
EXTRACT_SUFX=	.zip

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://hp.vector.co.jp/authors/VA000501/
COMMENT=	Quick Kanji code Converter

ALL_TARGET=	qkc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 ${PREFIX}/man/ja_JP.EUC/man1

.include "../../mk/bsd.pkg.mk"
