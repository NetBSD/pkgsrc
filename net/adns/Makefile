# $NetBSD: Makefile,v 1.10 2004/05/27 21:21:41 lukem Exp $
#

DISTNAME=	adns-1.1
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-dynamic

.include "../../mk/bsd.pkg.mk"
