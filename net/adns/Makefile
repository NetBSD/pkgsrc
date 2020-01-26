# $NetBSD: Makefile,v 1.25 2020/01/26 17:31:48 rillig Exp $
#

DISTNAME=	adns-1.5.1
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~ian/adns/
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
