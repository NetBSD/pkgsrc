# $NetBSD: Makefile,v 1.10 1998/11/12 23:03:40 frueauf Exp $
# FreeBSD Id: Makefile,v 1.1 1996/11/16 01:51:25 jdp Exp
#

DISTNAME=	gc4.12
PKGNAME=	boehm-gc-4.12
CATEGORIES=	devel
MASTER_SITES=	http://reality.sgi.com/employees/boehm_mti/gc_source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://reality.sgi.com/employees/boehm_mti/gc.html

NOT_FOR_ARCHS+=	sparc		# SEGV in "./test_cpp 1" in build: target
NOT_FOR_ARCHS+=	alpha		# needs dlopen, ELF, still SEGV's

WRKSRC=		${WRKDIR}/gc
ALL_TARGET=	BSD-pkg-all
INSTALL_TARGET=	BSD-pkg-install
MAKE_ENV+=	CP="${CP}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

.include "../../mk/bsd.pkg.mk"
