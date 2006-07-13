# $NetBSD: Makefile,v 1.3 2006/07/13 10:10:37 wiz Exp $

DISTNAME=		gnucash-1.8.12
PKGREVISION=		5
CATEGORIES=		finance
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal double-entry accounting program (GTK1 version)

DEPENDS+=		guile-slib-[0-9]*:../../devel/guile-slib
DEPENDS+=		p5-Date-Manip>=5.42a:../../devel/p5-Date-Manip
DEPENDS+= 		p5-Finance-Quote>=1.06:../../finance/p5-Finance-Quote

USE_DIRS+=		gnome1-1.5
USE_TOOLS+=		bison gmake intltool perl:run pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}

REPLACE_PERL=		src/quotes/dump-finance-quote

# code is using char/unsigned char inconsistently
BUILDLINK_TRANSFORM+=  rm:-Werror

AM_MAKEFLAGS=		LIBTOOL='${LIBTOOL} ${LIBTOOL_FLAGS}'
MAKE_ENV+=		AM_MAKEFLAGS=${AM_MAKEFLAGS:Q}

INFO_FILES=		# PLIST

# empty in 1.8.12, existed before
post-install:
	${RMDIR} ${PREFIX}/share/doc/gnucash

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../devel/g-wrap/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../math/guppi/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../www/gtkhtml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
