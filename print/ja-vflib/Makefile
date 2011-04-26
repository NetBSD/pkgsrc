# $NetBSD: Makefile,v 1.15 2011/04/26 11:54:15 joerg Exp $

DISTNAME=		ja-vflib-${VFLIB_VERSION}
VFLIB_VERSION=		2.24.2
PKGREVISION=		2
CATEGORIES=		japanese print

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www-masu.ist.osaka-u.ac.jp/~kakugawa/VFlib/
COMMENT=		Japanese Vector font libraries and utilities

META_PACKAGE=		yes

DEPENDS+=		ja-vflib-lib-${VFLIB_VERSION}{,nb[0-9]}*:../../print/ja-vflib-lib
DEPENDS+=		ja-vflib-utils-${VFLIB_VERSION}{,nb[0-9]*}:../../print/ja-vflib-utils

.include "../../mk/bsd.pkg.mk"
