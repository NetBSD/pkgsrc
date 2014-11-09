# $NetBSD: Makefile,v 1.10 2014/11/09 08:32:17 obache Exp $

DISTNAME=	libatomic_ops-7.4.2
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
