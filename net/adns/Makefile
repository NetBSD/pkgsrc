# $NetBSD: Makefile,v 1.26 2021/02/11 11:25:51 nia Exp $
#

DISTNAME=	adns-1.6.0
CATEGORIES=	net
MASTER_SITES=	https://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake gm4
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
# libtoolize patch to static library target.
CONFIGURE_ARGS+=	--disable-dynamic

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	libdir=${DESTDIR}${PREFIX}/lib

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
