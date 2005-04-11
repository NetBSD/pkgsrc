# $NetBSD: Makefile,v 1.15 2005/04/11 21:46:46 tv Exp $
#

DISTNAME=	echoping-5.2.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://echoping.sourceforge.net/
COMMENT=	Test performance of a remote TCP service

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-icp
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}

.include "../../devel/libidn/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
