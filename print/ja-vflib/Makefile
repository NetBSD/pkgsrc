# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:37 joerg Exp $

DISTNAME=		ja-vflib-${VFLIB_VERSION}
PKGREVISION=		1
VFLIB_VERSION=		2.24.2nb1
CATEGORIES=		japanese print
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://TypeHack.aial.hiroshima-u.ac.jp/VFlib/
COMMENT=		Japanese Vector font libraries and utilities

DEPENDS+=		ja-vflib-lib-${VFLIB_VERSION}nb2:../../print/ja-vflib-lib
DEPENDS+=		ja-vflib-utils-${VFLIB_VERSION}nb2:../../print/ja-vflib-utils


EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:		# empty

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
