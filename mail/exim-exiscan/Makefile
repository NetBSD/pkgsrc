# $NetBSD: Makefile,v 1.8 2004/03/26 02:27:43 wiz Exp $

DISTNAME=	exim-${EXIM_VERSION}
PKGREVISION=	3
PKGNAME=	exim-exiscan-${EXIM_VERSION}-${EXISCAN_VERSION}
CATEGORIES=	mail net

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://duncanthrax.net/exiscan-acl/
COMMENT=	The Exim mail transfer agent, with exiscan-acl patches

DEPENDS+=	exim-user>=1.0:../../mail/exim-user
CONFLICTS+=	exim-[0-9]*

EXISCAN_VERSION=12

PATCH_SITES=    http://duncanthrax.net/exiscan-acl/
PATCHFILES=     exiscan-acl-${EXIM_VERSION}-${EXISCAN_VERSION}.patch

DISTINFO_FILE=	${.CURDIR}/../../mail/exim/distinfo
PATCHDIR=	${.CURDIR}/../../mail/exim/patches
FILESDIR=	${.CURDIR}/../../mail/exim/files
PLIST_SRC=	${.CURDIR}/../../mail/exim/PLIST

.include "../../mail/exim/Makefile.common"

PATCH_DIST_ARGS+=-p1

