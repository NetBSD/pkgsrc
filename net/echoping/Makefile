# $NetBSD: Makefile,v 1.9 2003/11/12 03:39:41 jschauma Exp $
#

DISTNAME=	echoping-4.1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://echoping.sourceforge.net/
COMMENT=	Test performance of a remote TCP service

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-icp
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
