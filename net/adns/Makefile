# $NetBSD: Makefile,v 1.22 2012/10/23 17:18:08 asau Exp $
#

DISTNAME=	adns-1.4
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
# libtoolize patch to static library target.
CONFIGURE_ARGS+=	--disable-dynamic

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
