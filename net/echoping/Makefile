# $NetBSD: Makefile,v 1.4 2002/06/17 10:06:52 drochner Exp $
#

DISTNAME=	echoping-4.1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://echoping.sourceforge.net/
COMMENT=	test performance of a remote TCP service

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-icp
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}

USE_BUILDLINK_ONLY=	yes

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
