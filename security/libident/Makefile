# $NetBSD: Makefile,v 1.9 2002/10/22 11:44:58 wiz Exp $
#

DISTNAME=	libident-0.22
CATEGORIES=	security devel net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/libs/

MAINTAINER=	packages@netbsd.org
COMMENT=	Small library to interface to the ident protocol server (rfc1413)

USE_BUILDLINK2=	# defined
USE_LIBTOOL=	# defined

ALL_TARGET=	netbsd
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"

.include "../../mk/bsd.pkg.mk"
