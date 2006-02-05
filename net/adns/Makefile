# $NetBSD: Makefile,v 1.16 2006/02/05 23:10:22 joerg Exp $
#

DISTNAME=	adns-1.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-dynamic

.include "../../mk/bsd.pkg.mk"
