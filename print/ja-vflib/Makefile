# $NetBSD: Makefile,v 1.5 2005/06/01 18:03:20 jlam Exp $

DISTNAME=		ja-vflib-${VFLIB_VERSION}
VFLIB_VERSION=		2.24.2nb1
CATEGORIES=		japanese print
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://TypeHack.aial.hiroshima-u.ac.jp/VFlib/
COMMENT=		Japanese Vector font libraries and utilities

DEPENDS+=		ja-vflib-lib-${VFLIB_VERSION}:../../print/ja-vflib-lib
DEPENDS+=		ja-vflib-utils-${VFLIB_VERSION}:../../print/ja-vflib-utils


EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
