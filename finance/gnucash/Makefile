# $NetBSD: Makefile,v 1.37 2003/02/23 13:03:06 jmmv Exp $

DISTNAME=		gnucash-1.6.8
PKGREVISION=		3
CATEGORIES=		finance
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal double-entry accounting program

BUILDLINK_DEPENDS.g-wrap=	g-wrap>=1.2.1:../../devel/g-wrap
BUILDLINK_DEPENDS.g-wrap+=	g-wrap<1.3.0:../../devel/g-wrap
BUILDLINK_DEPENDS.guile14=	guile14>=1.4:../../lang/guile14
BUILDLINK_DEPENDS.guile14+=	guile14<1.5.0:../../lang/guile14
BUILD_DEPENDS+=			bison>=1.28:../../devel/bison

USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_FLAGS+=		--preserve-dup-deps
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ENV+=		GUILE="${GUILE14}"
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${PREFIX}/lib/pkgconfig:${X11BASE}/lib/pkgconfig"

AM_MAKEFLAGS=		LIBTOOL='${PKGLIBTOOL} ${LIBTOOL_FLAGS}'
MAKE_ENV+=		AM_MAKEFLAGS="${AM_MAKEFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
post-buildlink:
	${LN} -s /usr/include/db.h ${BUILDLINK_DIR}/include/db_185.h
	if [ ! -f /usr/include/wctype.h ]; then				\
		${TOUCH} ${BUILDLINK_DIR}/include/wctype.h;		\
	fi
.endif

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../devel/g-wrap/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/swig/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../math/guppi/buildlink2.mk"
.include "../../net/ORBit/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
