# $NetBSD: Makefile,v 1.7 2004/01/22 12:20:33 xtraeme Exp $
#

DISTNAME=	adns-1.1
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-dynamic

.include "../../mk/bsd.pkg.mk"
