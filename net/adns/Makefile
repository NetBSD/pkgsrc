# $NetBSD: Makefile,v 1.15 2005/12/05 20:50:44 rillig Exp $
#

DISTNAME=	adns-1.1
PKGREVISION=	1
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
