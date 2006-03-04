# $NetBSD: Makefile,v 1.17 2006/03/04 21:30:16 jlam Exp $
#

DISTNAME=	adns-1.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-dynamic

.include "../../mk/bsd.pkg.mk"
