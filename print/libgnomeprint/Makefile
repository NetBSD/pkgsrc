# $NetBSD: Makefile,v 1.17 2003/09/27 21:05:22 danw Exp $
#

DISTNAME=		libgnomeprint-2.2.1.2
PKGREVISION=		2
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomeprint/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Library for the GNOME2 Printing Architecture

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgnomeprint/libgnomeprint-2.2.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_CUPS
.if defined(USE_CUPS) && !empty(USE_CUPS:M[Yy][Ee][Ss])
.include "../../print/cups/buildlink2.mk"
CONFIGURE_ARGS+=	--with-cups
.else
CONFIGURE_ARGS+=	--without-cups
.endif

.if ${OPSYS} == "Darwin"
# AC_LTDL_SHLIBEXT doesn't work on Darwin (and would give the wrong
# answer here even if it did).
CONFIGURE_ENV+=		libltdl_cv_shlibext=so
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
