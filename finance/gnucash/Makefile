# $NetBSD: Makefile,v 1.80 2005/02/09 20:20:50 wiz Exp $

DISTNAME=		gnucash-1.8.11
CATEGORIES=		finance
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal double-entry accounting program

DEPENDS+=		p5-Date-Manip>=5.42a:../../devel/p5-Date-Manip
DEPENDS+= 		p5-finance-quote>=1.06:../../finance/p5-finance-quote

BUILD_DEPENDS+=		bison>=1.28:../../devel/bison

USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}

# code is using char/unsigned char inconsistently
BUILDLINK_TRANSFORM+=  rm:-Werror

AM_MAKEFLAGS=		LIBTOOL='${LIBTOOL} ${LIBTOOL_FLAGS}'
MAKE_ENV+=		AM_MAKEFLAGS=${AM_MAKEFLAGS:Q}

INFO_FILES=		gnucash-design.info

.include "../../mk/bsd.prefs.mk"

#.if ${OPSYS} == "NetBSD"
#post-wrapper:
#	if [ ! -f /usr/include/wctype.h ]; then				\
#		${TOUCH} ${BUILDLINK_DIR}/include/wctype.h;		\
#	fi
#.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../devel/g-wrap1/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../math/guppi/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../www/gtkhtml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
