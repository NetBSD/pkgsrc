# $NetBSD: Makefile,v 1.2 2003/09/19 18:03:34 jmmv Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/09/15 22:05:58 kuriyama Exp

DISTNAME=	ack139
PKGNAME=	ack-1.39
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.tohoku.ac.jp/pub/unix/ack/

MAINTAINER=	kei_sun@ba2.so-net.ne.jp
COMMENT=	Japanese code converter

ALL_TARGET=     ack

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ack ${PREFIX}/bin/ack
	${INSTALL_DATA} ${WRKSRC}/ack.1 ${PREFIX}/man/ja_JP.EUC/man1/ack.1

.include "../../mk/bsd.pkg.mk"
