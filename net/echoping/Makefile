# $NetBSD: Makefile,v 1.6 2003/06/02 01:18:00 jschauma Exp $
#

DISTNAME=	echoping-4.1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://echoping.sourceforge.net/
COMMENT=	test performance of a remote TCP service

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-icp
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
