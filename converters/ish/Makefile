# $NetBSD: Makefile,v 1.2 2001/02/16 13:59:24 wiz Exp $

DISTNAME=	ish-1.11
CATEGORIES=	converters
MASTER_SITES=	ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	packages@netbsd.org
COMMENT=	Binary-to-text file-encoder

MAKEFILE=	makefile
ALL_TARGET=	ish

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ish ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
