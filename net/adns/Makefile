# $NetBSD: Makefile,v 1.5 2002/10/09 17:56:50 wiz Exp $
#

DISTNAME=	adns-1.0
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-dynamic

.include "../../mk/bsd.pkg.mk"
