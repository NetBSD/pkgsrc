# $NetBSD: Makefile,v 1.4 2005/03/24 21:12:52 wiz Exp $

DISTNAME=	ack139
PKGNAME=	ack-1.39
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.tohoku.ac.jp/pub/unix/ack/

MAINTAINER=	kei_sun@ba2.so-net.ne.jp
COMMENT=	Japanese code converter

BUILD_TARGET=     ack

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ack ${PREFIX}/bin/ack
	${INSTALL_DATA} ${WRKSRC}/ack.1 ${PREFIX}/man/ja_JP.EUC/man1/ack.1

.include "../../mk/bsd.pkg.mk"
