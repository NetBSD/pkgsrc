# $NetBSD: Makefile,v 1.7 1998/08/20 15:16:46 tsarna Exp $
# FreeBSD Id: Makefile,v 1.1 1996/11/16 01:51:25 jdp Exp
#

DISTNAME=	gc4.12
PKGNAME=	boehm-gc-4.12
CATEGORIES=	devel
MASTER_SITES=	http://reality.sgi.com/employees/boehm_mti/gc_source/

MAINTAINER=	mmcg@cs.monash.edu.au
HOMEPAGE=	http://reality.sgi.com/employees/boehm_mti/gc.html

WRKSRC=		${WRKDIR}/gc
ALL_TARGET=	BSD-pkg-all
INSTALL_TARGET=	BSD-pkg-install
MAKE_ENV+=	CP="${CP}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

.include "../../mk/bsd.pkg.mk"
