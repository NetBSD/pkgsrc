# $NetBSD: Makefile,v 1.11 2003/08/09 10:53:26 seb Exp $

PKGNAME=	aalib-${BASE_VERS}
PKGREVISION=	1
CONFLICTS+=	aalib-x11<=1.4.0.4

COMMENT=	ASCII Art library

USE_BUILDLINK2=		YES
CONFIGURE_ARGS+=	--with-x11-driver=no

INFO_FILES=	aalib.info

.include "Makefile.common"
