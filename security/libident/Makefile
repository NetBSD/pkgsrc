# $NetBSD: Makefile,v 1.8 2001/02/17 17:49:50 wiz Exp $
# FreeBSD ID: Makefile,v 1.6 1998/01/25 20:42:37 torstenb Exp

DISTNAME=	libident-0.22
CATEGORIES=	security devel net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/libs/

MAINTAINER=	packages@netbsd.org
COMMENT=	Small library to interface to the ident protocol server (rfc1413)

USE_LIBTOOL=	# defined

ALL_TARGET=	netbsd
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"

.include "../../mk/bsd.pkg.mk"
