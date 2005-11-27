# $NetBSD: Makefile,v 1.11 2005/11/27 17:05:29 adrianp Exp $

.include "Makefile.common"

PKGNAME=	ghostscript-esp-${GS_VERS}
PKGREVISION=	1
COMMENT=	ESP/CUPS Postscript interpreter

CONFIGURE_ARGS+=	--with-x

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
