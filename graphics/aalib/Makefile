# $NetBSD: Makefile,v 1.10 2003/07/03 13:09:47 seb Exp $

PKGNAME=	aalib-${BASE_VERS}
PKGREVISION=	1
CONFLICTS+=	aalib-x11<=1.4.0.4

COMMENT=	ASCII Art library

USE_BUILDLINK2=		YES
CONFIGURE_ARGS+=	--with-x11-driver=no

USE_NEW_TEXINFO=	YES
INFO_FILES=	aalib.info

.include "Makefile.common"
