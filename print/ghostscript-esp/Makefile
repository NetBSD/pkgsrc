# $NetBSD: Makefile,v 1.9.4.1 2005/12/11 12:04:26 seb Exp $

.include "Makefile.common"

PKGNAME=	ghostscript-esp-${GS_VERS}
PKGREVISION=	1
COMMENT=	ESP/CUPS Postscript interpreter

CONFIGURE_ARGS+=	--with-x

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
