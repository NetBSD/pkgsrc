# $NetBSD: Makefile,v 1.18 2007/10/10 08:38:41 rillig Exp $
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
INSTALLATION_DIRS_FROM_PLIST=	yes

.include "../../mk/bsd.pkg.mk"
