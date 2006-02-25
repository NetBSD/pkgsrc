# $NetBSD: Makefile,v 1.13.2.1 2006/02/25 01:25:46 salo Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	xfce4-print-${XFCE4_VERSION}
DISTNAME=	xfprint-${XFCE4_VERSION}
CATEGORIES=	print
COMMENT=	Xfce print dialog

CONFIGURE_ARGS+=	--with-printcap=/etc/printcap

.include "options.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	SOLARIS="@comment "
.else
PLIST_SUBST+=	SOLARIS=""
.endif

.include "../../print/a2ps/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
