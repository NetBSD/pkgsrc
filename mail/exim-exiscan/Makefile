# $NetBSD: Makefile,v 1.12 2004/06/06 22:10:51 abs Exp $

DISTNAME=	exim-${EXIM_VERSION}
PKGNAME=	exim-exiscan-${EXIM_VERSION}_${EXISCAN_VERSION}
CATEGORIES=	mail net

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://duncanthrax.net/exiscan-acl/
COMMENT=	The Exim mail transfer agent, with exiscan-acl patches

CONFLICTS+=	exim-[0-9]*

EXISCAN_VERSION=22

PATCH_SITES=    http://duncanthrax.net/exiscan-acl/
PATCHFILES=     exiscan-acl-${EXIM_VERSION}-${EXISCAN_VERSION}.patch.bz2

DISTINFO_FILE=	${.CURDIR}/../../mail/exim/distinfo
PATCHDIR=	${.CURDIR}/../../mail/exim/patches
FILESDIR=	${.CURDIR}/../../mail/exim/files
PLIST_SRC=	${.CURDIR}/../../mail/exim/PLIST

.include "../../mail/exim/Makefile.common"

PATCH_DIST_ARGS+=-p1

