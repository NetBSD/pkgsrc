# $NetBSD: Makefile,v 1.10.2.1 2002/06/06 06:54:42 jlam Exp $

DISTNAME=		ja-vflib-${VFLIB_VERSION}
VFLIB_VERSION=		2.24.2
CATEGORIES=		japanese print
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://TypeHack.aial.hiroshima-u.ac.jp/VFlib/
COMMENT=		Japanese Vector font libraries and utilities

DEPENDS+=		ja-vflib-lib-${VFLIB_VERSION}:../../japanese/vflib-lib
DEPENDS+=		ja-vflib-utils-${VFLIB_VERSION}:../../japanese/vflib-utils

USE_X11=		# defined	# ja-vflib-utils uses X11
USE_BUILDLINK2_ONLY=	# defined

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
