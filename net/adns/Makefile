# $NetBSD: Makefile,v 1.12 2004/10/03 00:17:49 tv Exp $
#

DISTNAME=	adns-1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-dynamic

.include "../../mk/bsd.pkg.mk"
