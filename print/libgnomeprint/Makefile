# $NetBSD: Makefile,v 1.33 2004/10/03 00:18:05 tv Exp $
#

DISTNAME=	libgnomeprint-2.8.0
PKGREVISION=	1
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeprint/2.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.levien.com/gnome/print-arch.html
COMMENT=	Library for the GNOME2 Printing Architecture

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.1.4

PKGCONFIG_OVERRIDE=	libgnomeprint/libgnomeprint-2.2.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgnomeprint
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/libgnomecups/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cups
PLIST_SUBST+=		USE_CUPS=
.else
CONFIGURE_ARGS+=	--without-cups
PLIST_SUBST+=		USE_CUPS="@comment "
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# AC_LTDL_SHLIBEXT doesn't work on Darwin (and would give the wrong
# answer here even if it did).
CONFIGURE_ENV+=		libltdl_cv_shlibext=so
.endif

PRINT_PLIST_AWK+=	/cups/ { print "$${USE_CUPS}" $$0; next; }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
