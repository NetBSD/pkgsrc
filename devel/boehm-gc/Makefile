# New ports collection makefile for:	boehm-gc
# Version required:	4.12
# Date created:		15 November 1996
# Whom:			Mike McGaughey <mmcg@cs.monash.edu.au>
#
# $NetBSD: Makefile,v 1.4 1998/02/26 16:48:55 agc Exp $
# FreeBSD Id: Makefile,v 1.1 1996/11/16 01:51:25 jdp Exp
#

DISTNAME=	gc4.12
PKGNAME=	boehm-gc-4.12
CATEGORIES=	devel
MASTER_SITES=	http://reality.sgi.com/employees/boehm_mti/gc_source/

MAINTAINER=	mmcg@cs.monash.edu.au

WRKSRC=		${WRKDIR}/gc
MAN3=		gc.3
ALL_TARGET=	BSD-pkg-all
INSTALL_TARGET=	BSD-pkg-install
MAKE_ENV+=	CP="${CP}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

.include <bsd.port.mk>
