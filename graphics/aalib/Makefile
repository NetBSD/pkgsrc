# $NetBSD: Makefile,v 1.9 2002/08/26 19:38:05 jlam Exp $

PKGNAME=	aalib-${BASE_VERS}
PKGREVISION=	1
CONFLICTS+=	aalib-x11<=1.4.0.4

COMMENT=	ASCII Art library

USE_BUILDLINK2=		YES
CONFIGURE_ARGS+=	--with-x11-driver=no

.include "Makefile.common"
