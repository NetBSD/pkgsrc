# $NetBSD: Makefile,v 1.11 2005/05/18 12:16:53 abs Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	xfce4-print-${XFCE4_VERSION}
DISTNAME=	xfprint-${XFCE4_VERSION}
CATEGORIES=	print
COMMENT=	XFce4 print dialog

CONFIGURE_ARGS+=	--with-printcap=/etc/printcap

.include "../../print/a2ps/buildlink3.mk"

.if defined(USE_CUPS)
.include "../../print/cups/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
