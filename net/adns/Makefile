# $NetBSD: Makefile,v 1.9 2004/04/25 08:01:15 snj Exp $
#

DISTNAME=	adns-1.1
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-dynamic

.include "../../mk/bsd.pkg.mk"
