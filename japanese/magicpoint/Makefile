# New ports collection makefile for:	magicpoint (with vflib)
# Version required:	1.04a
# Date created:		25 Dec 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.1.1.1 1999/06/17 07:53:08 itojun Exp $
#

MASTERDIR=	${.CURDIR}/../../graphics/magicpoint
COMMENT=	${.CURDIR}/pkg/COMMENT
DESCR_SRC=	${MASTERDIR}/pkg/DESCR
PLIST_SRC=	${MASTERDIR}/pkg/PLIST

PKGNAME=	ja-magicpoint-1.05a

#LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib
CONFIGURE_ARGS=	--disable-vflib --enable-freetype-charset16

.include "${MASTERDIR}/Makefile"

CATEGORIES=	japanese misc

MAINTAINER=	itojun@itojun.org
