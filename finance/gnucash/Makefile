# $NetBSD: Makefile,v 1.62 2004/04/25 04:16:43 xtraeme Exp $

DISTNAME=		gnucash-1.8.8
PKGREVISION=		5
CATEGORIES=		finance
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal double-entry accounting program

DEPENDS+=		p5-Date-Manip>=5.42a:../../devel/p5-Date-Manip
DEPENDS+= 		p5-finance-quote>=1.06:../../finance/p5-finance-quote

BUILDLINK_DEPENDS.guile14+=	guile14<1.5.0:../../lang/guile14

BUILD_DEPENDS+=			bison>=1.28:../../devel/bison

USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
# LIBTOOL_FLAGS+=		--preserve-dup-deps
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ENV+=		GUILE="${GUILE14}"
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${PREFIX}/lib/pkgconfig:${X11BASE}/lib/pkgconfig"

AM_MAKEFLAGS=		LIBTOOL='${LIBTOOL} ${LIBTOOL_FLAGS}'
MAKE_ENV+=		AM_MAKEFLAGS="${AM_MAKEFLAGS}"

INFO_FILES=		gnucash-design.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
post-buildlink:
	${LN} -s /usr/include/db.h ${BUILDLINK_DIR}/include/db_185.h
	if [ ! -f /usr/include/wctype.h ]; then				\
		${TOUCH} ${BUILDLINK_DIR}/include/wctype.h;		\
	fi
.endif

GNUCASH_GUILE_MAKEFILE_IN_FILES= \
	src/app-file/Makefile.in src/app-utils/Makefile.in \
	src/business/business-core/Makefile.in \
	src/business/business-gnome/Makefile.in \
	src/business/dialog-tax-table/Makefile.in \
	src/core-utils/Makefile.in \
	src/engine/Makefile.in \
	src/gnc-module/Makefile.in \
	src/gnc-module/test/mod-bar/Makefile.in \
	src/gnc-module/test/mod-baz/Makefile.in \
	src/gnc-module/test/mod-foo/Makefile.in \
	src/gnome-search/Makefile.in \
	src/gnome-utils/Makefile.in \
	src/gnome/Makefile.in \
	src/import-export/binary-import/Makefile.in \
	src/register/register-core/Makefile.in \
	src/report/report-gnome/Makefile.in

post-patch:
	cd ${WRKSRC};							\
	for f in ${GNUCASH_GUILE_MAKEFILE_IN_FILES}; do			\
		${MV} $$f $$f.orig;					\
		${SED} -e 's|gnome guile|gnome $${GUILE}|g' $$f.orig > $$f;	\
	done

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../devel/g-wrap/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/swig/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../math/guppi/buildlink2.mk"
.include "../../net/ORBit/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
