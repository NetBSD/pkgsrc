# $NetBSD: Makefile,v 1.8.2.1 2004/05/30 09:05:12 grant Exp $

DISTNAME=	exim-${EXIM_VERSION}
PKGREVISION=	1
PKGNAME=	exim-exiscan-${EXIM_VERSION}_${EXISCAN_VERSION}
CATEGORIES=	mail net

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://duncanthrax.net/exiscan-acl/
COMMENT=	The Exim mail transfer agent, with exiscan-acl patches

CONFLICTS+=	exim-[0-9]*

EXISCAN_VERSION=20

PATCH_SITES=    http://duncanthrax.net/exiscan-acl/
PATCHFILES=     exiscan-acl-${EXIM_VERSION}-${EXISCAN_VERSION}.patch.bz2

DISTINFO_FILE=	${.CURDIR}/../../mail/exim/distinfo
PATCHDIR=	${.CURDIR}/../../mail/exim/patches
FILESDIR=	${.CURDIR}/../../mail/exim/files
PLIST_SRC=	${.CURDIR}/../../mail/exim/PLIST

.include "../../mail/exim/Makefile.common"

PATCH_DIST_ARGS+=-p1

