# $NetBSD: Makefile,v 1.66 2004/10/05 23:20:53 mjl Exp $

DISTNAME=		gnucash-1.8.9
# PKGREVISION=		6
CATEGORIES=		finance
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal double-entry accounting program

DEPENDS+=		p5-Date-Manip>=5.42a:../../devel/p5-Date-Manip
DEPENDS+= 		p5-finance-quote>=1.06:../../finance/p5-finance-quote

BUILD_DEPENDS+=			bison>=1.28:../../devel/bison

USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${PREFIX}/lib/pkgconfig:${X11BASE}/lib/pkgconfig"

CFLAGS+=		-Wl,-R${PREFIX}/${GUILE14_SUBDIR}/lib
#CFLAGS+=		-L${PREFIX}/${GUILE14_SUBDIR}/lib -Wl,-R${PREFIX}/${GUILE14_SUBDIR}/lib
LDFLAGS+=		-L${PREFIX}/${GUILE14_SUBDIR}/lib -Wl,-R${PREFIX}/${GUILE14_SUBDIR}/lib

AM_MAKEFLAGS=		LIBTOOL='${LIBTOOL} ${LIBTOOL_FLAGS}'
MAKE_ENV+=		AM_MAKEFLAGS="${AM_MAKEFLAGS}"
MAKE_ENV+=		GUILE14_SUBDIR=${GUILE14_SUBDIR:Q}

INFO_FILES=		gnucash-design.info

SUBST_CLASSES+=		guile14
SUBST_STAGE.guile14=	pre-configure
SUBST_MESSAGE.guile14=	"Substitute interpreter calls to use guile14."
SUBST_FILES.guile14+=	src/bin/overrides/gnucash
SUBST_FILES.guile14+=	src/bin/overrides/gnucash-make-guids
SUBST_FILES.guile14+=	src/bin/overrides/gnucash-run-script
SUBST_SED.guile14+=	"s, guile , ${PREFIX}/${GUILE14_SUBDIR}/bin/guile ,"

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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../devel/g-wrap/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../lang/guile14/buildlink3.mk"
.include "../../math/guppi/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../www/gtkhtml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
