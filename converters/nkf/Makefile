# $NetBSD: Makefile,v 1.2 2004/01/26 05:08:13 cjs Exp $

DISTNAME=	nkf204
PKGNAME=	nkf-2.04
CATEGORIES=	japanese converters
MASTER_SITES=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://www.jazzdisco.org/bsdi/software/nkf/
COMMENT=	Convert between various Japanese character encodings

ALL_TARGET=	nkf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nkf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nkf.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
