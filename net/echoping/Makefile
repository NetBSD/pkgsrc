# $NetBSD: Makefile,v 1.3 2001/02/17 18:18:49 wiz Exp $
#

DISTNAME=	echoping-4.1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://echoping.sourceforge.net/
COMMENT=	test performance of a remote TCP service

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=--enable-icp
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}

.include "../../mk/bsd.pkg.mk"
