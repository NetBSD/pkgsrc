# New ports collection makefile for:	magicpoint
# Version required:	1.05a
# Date created:		25 Dec 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $NetBSD: Makefile,v 1.2 1999/06/17 08:02:37 itojun Exp $
# Based on FreeBSD Id: Makefile,v 1.7 1998/12/23 01:31:37 steve Exp
#

MASTERDIR=	${.CURDIR}/../../graphics/magicpoint
COMMENT=	${.CURDIR}/pkg/COMMENT
DESCR_SRC=	${MASTERDIR}/pkg/DESCR
PLIST_SRC=	${MASTERDIR}/pkg/PLIST
FILESDIR=	${MASTERDIR}/files
PATCHDIR=	${MASTERDIR}/patches

PKGNAME=	ja-magicpoint-1.05a

#LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib
CONFIGURE_ARGS=	--disable-vflib --enable-freetype-charset16

.include "${MASTERDIR}/Makefile"

CATEGORIES+=	japanese

MAINTAINER=	itojun@itojun.org
