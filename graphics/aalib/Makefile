# $NetBSD: Makefile,v 1.14 2005/03/29 14:28:05 wiz Exp $

PKGNAME=	aalib-${BASE_VERS}
CONFLICTS+=	aalib-x11<=1.4.0.4

COMMENT=	ASCII Art library

USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--with-x11-driver=no

INFO_FILES=	aalib.info

.include "Makefile.common"
