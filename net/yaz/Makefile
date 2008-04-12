# $NetBSD: Makefile,v 1.14 2008/04/12 22:40:22 jlam Exp $
#

DISTNAME=	yaz-2.1.56
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	phil@NetBSD.org
HOMEPAGE=	http://indexdata.dk/yaz/
COMMENT=	C/C++ toolkit for the development of Z39.50v3/SRW clients and servers

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

PTHREAD_OPTS+=	native optional

.include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xml2=${BUILDLINK_PREFIX.libxml2}

.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.libiconv}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
