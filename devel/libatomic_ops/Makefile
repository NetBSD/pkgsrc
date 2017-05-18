# $NetBSD: Makefile,v 1.12 2017/05/18 20:37:03 adam Exp $

DISTNAME=	libatomic_ops-7.4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ivmai/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ivmai/libatomic_ops
COMMENT=	Multi-platform library of atomic operations by Hans Boehm
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	libatomic_ops
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

USE_LANGUAGES+=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	pkgconfig/atomic_ops.pc.in
TEST_TARGET=		check

INSTALL_MAKE_FLAGS=	pkgdatadir=${PREFIX}/share/doc/libatomic_ops

.include "../../mk/bsd.pkg.mk"
