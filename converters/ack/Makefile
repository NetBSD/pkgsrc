# $NetBSD: Makefile,v 1.6 2007/01/07 09:13:49 rillig Exp $

DISTNAME=	ack139
PKGNAME=	ack-1.39
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.tohoku.ac.jp/pub/unix/ack/

MAINTAINER=	kei_sun@ba2.so-net.ne.jp
COMMENT=	Japanese code converter

BUILD_TARGET=     ack

INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.EUC/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ack ${PREFIX}/bin/ack
	${INSTALL_DATA} ${WRKSRC}/ack.1 ${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/ack.1

.include "../../mk/bsd.pkg.mk"
