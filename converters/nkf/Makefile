# $NetBSD: Makefile,v 1.7 2005/06/25 04:41:14 taca Exp $

DISTNAME=	nkf205
PKGNAME=	nkf-2.05
CATEGORIES=	japanese converters
MASTER_SITES=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/
COMMENT=	Convert between various Japanese character encodings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin man/man1

BUILD_TARGET=	nkf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nkf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nkf.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
