# $NetBSD: Makefile,v 1.5 2001/01/21 20:42:17 tron Exp $

DISTNAME=	zlib-1.1.3
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.freesoftware.com/pub/infozip/zlib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://ftp.freesoftware.com/pub/infozip/zlib/index.html

ONLY_FOR_PLATFORM=	SunOS-*-* # in base NetBSD system

MAKEFILE=	bsd.mk
MAKE_ENV+=	NOLINT=yes

INSTALL_TARGET=	install includes

.include "../../mk/bsd.pkg.mk"
