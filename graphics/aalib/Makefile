# $NetBSD: Makefile,v 1.12 2004/02/11 08:44:23 xtraeme Exp $

PKGNAME=	aalib-${BASE_VERS}
PKGREVISION=	1
CONFLICTS+=	aalib-x11<=1.4.0.4

COMMENT=	ASCII Art library

USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--with-x11-driver=no

INFO_FILES=	aalib.info

.include "Makefile.common"
