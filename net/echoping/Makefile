# $NetBSD: Makefile,v 1.7 2003/07/17 22:51:08 grant Exp $
#

DISTNAME=	echoping-4.1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://echoping.sourceforge.net/
COMMENT=	test performance of a remote TCP service

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-icp
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
