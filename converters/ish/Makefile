# $NetBSD: Makefile,v 1.1.1.1 2000/11/14 21:18:52 itojun Exp $

DISTNAME=	ish-1.11
CATEGORIES=	converters
MASTER_SITES=	ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
ALL_TARGET=	ish

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ish ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
