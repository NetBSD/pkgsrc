# $NetBSD: Makefile,v 1.5 2004/12/03 15:14:52 wiz Exp $

DISTNAME=	nkf204
PKGNAME=	nkf-2.04
CATEGORIES=	japanese converters
MASTER_SITES=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://www.jazzdisco.org/bsdi/software/nkf/
COMMENT=	Convert between various Japanese character encodings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin man/man1

BUILD_TARGET=	nkf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nkf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nkf.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
