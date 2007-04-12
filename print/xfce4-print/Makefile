# $NetBSD: Makefile,v 1.20 2007/04/12 09:55:12 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	xfce4-print-${XFCE4_VERSION}
DISTNAME=	xfprint-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	print
COMMENT=	Xfce print dialog

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc
CONFIGURE_ARGS+=	--with-printcap=/etc/printcap

.include "options.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	SOLARIS="@comment "
.else
PLIST_SUBST+=	SOLARIS=""
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/a2ps/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
