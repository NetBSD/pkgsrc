# $NetBSD: Makefile,v 1.14 2000/06/26 17:03:01 rh Exp $
#

DISTNAME=		gnucash-1.4.1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			http://download.sourceforge.net/gnucash/

MAINTAINER=		drankin@bohemians.lexington.ky.us
HOMEPAGE=		http://www.gnucash.org/

DEPENDS+=		gnome-libs>=1.0.40:../../x11/gnome-libs
DEPENDS+=		gettext>=0.10.35:../../devel/gettext
DEPENDS+=		eperl-2.2.14:../../textproc/eperl
DEPENDS+=		libperl-5.00404:../../lang/libperl
DEPENDS+=		g-wrap>=0.9.4:../../devel/g-wrap
DEPENDS+=		guile-slib-2c7:../../devel/guile-slib
DEPENDS+=		swig-1.1p5:../../devel/swig
DEPENDS+=		libxml>=1.8.7:../../textproc/libxml

USE_GMAKE=		# defined
USE_PERL=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE+=	${WRKSRC}/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/lib/g-wrap/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-guile-config=${LOCALBASE}/bin/guile-config
CONFIGURE_ARGS+=	--without-motif --without-included-gettext
CONFIGURE_ARGS+= \
    --with-perl-includes=${LOCALBASE}/lib/perl5/${MACHINE_ARCH}-netbsd/5.00404
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
