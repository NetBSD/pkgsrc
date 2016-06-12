# $NetBSD: Makefile,v 1.11 2016/06/12 14:33:57 wiz Exp $

DISTNAME=	libatomic_ops-7.4.4
CATEGORIES=	devel
MASTER_SITES=	http://www.ivmaisoft.com/_bin/atomic_ops/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ivmai/libatomic_ops/wiki
COMMENT=	Multi-platform library of atomic operations by Hans Boehm
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
TEST_TARGET=	check
PKGCONFIG_OVERRIDE=	pkgconfig/atomic_ops.pc.in

INSTALL_MAKE_FLAGS=	pkgdatadir=${PREFIX}/share/doc/libatomic_ops

.include "../../mk/bsd.pkg.mk"
