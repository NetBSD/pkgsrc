# $NetBSD: Makefile,v 1.24 2008/12/20 18:59:52 reed Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	xfce4-print-${XFCE4_VERSION}
DISTNAME=	xfprint-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	print
COMMENT=	Xfce print dialog
HOMEPAGE=	http://www.xfce.org/projects/xfprint/

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc
CONFIGURE_ARGS+=	--with-printcap=/etc/printcap

.include "options.mk"

PLIST_VARS+=	bsdlpr
.if ${OPSYS} != "SunOS"
PLIST.bsdlpr=	yes
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/a2ps/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
