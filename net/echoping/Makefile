# $NetBSD: Makefile,v 1.2 2001/02/14 16:42:02 wiz Exp $
#

DISTNAME=	echoping-4.1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://echoping.sourceforge.net/

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=--enable-icp
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}

.include "../../mk/bsd.pkg.mk"
