# $NetBSD: Makefile,v 1.7 2014/04/16 11:21:32 wiz Exp $

DISTNAME=	libatomic_ops-7.4.0
CATEGORIES=	devel
MASTER_SITES=	http://www.ivmaisoft.com/atomic_ops/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ivmai/libatomic_ops/wiki
COMMENT=	Multi-platform library of atomic operations by Hans Boehm
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
TEST_TARGET=	check
PKGCONFIG_OVERRIDE=	pkgconfig/atomic_ops.pc

INSTALL_MAKE_FLAGS=	pkgdatadir=${PREFIX}/share/doc/libatomic_ops

.include "../../mk/bsd.pkg.mk"
