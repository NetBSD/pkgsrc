# $NetBSD: Makefile,v 1.108 2018/11/14 22:22:18 kleink Exp $
#

DISTNAME=	libgnomeprint-2.18.8
PKGREVISION=	32
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeprint/2.18/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.levien.com/gnome/print-arch.html
COMMENT=	Library for the GNOME2 Printing Architecture

USE_TOOLS+=		bison flex gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gtk-doc

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.4

PKGCONFIG_OVERRIDE=	libgnomeprint/libgnomeprint-2.2.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgnomeprint
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/libgnomecups/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cups
PLIST.cups=		yes
.else
CONFIGURE_ARGS+=	--without-cups
.endif

CONFIGURE_ARGS+=	--without-papi

# AC_LTDL_SHLIBEXT doesn't work on Darwin (and would give the wrong
# answer here even if it did).
CONFIGURE_ENV.Darwin+=	libltdl_cv_shlibext=so

PRINT_PLIST_AWK+=	/cups/ { print "$${USE_CUPS}" $$0; next; }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
