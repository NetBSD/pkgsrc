# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:48 tv Exp $

PKGNAME=	aalib-${BASE_VERS}
PKGREVISION=	2
CONFLICTS+=	aalib-x11<=1.4.0.4

COMMENT=	ASCII Art library

USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--with-x11-driver=no

INFO_FILES=	aalib.info

.include "Makefile.common"
