# $NetBSD: Makefile,v 1.8 2014/05/12 22:46:49 pho Exp $

DISTNAME=	libatomic_ops-7.4.0
CATEGORIES=	devel
MASTER_SITES=	http://www.ivmaisoft.com/atomic_ops/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ivmai/libatomic_ops/wiki
COMMENT=	Multi-platform library of atomic operations by Hans Boehm
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake gmake
USE_LIBTOOL=	yes
TEST_TARGET=	check
PKGCONFIG_OVERRIDE=	pkgconfig/atomic_ops.pc

INSTALL_MAKE_FLAGS=	pkgdatadir=${PREFIX}/share/doc/libatomic_ops

pre-configure:
	${RUN}cd ${WRKSRC} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
