# $NetBSD: Makefile,v 1.13 2000/06/21 05:38:21 jlam Exp $
#

DISTNAME=		gnucash-1.3.7
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/unstable/1.3.x/

MAINTAINER=		drankin@bohemians.lexington.ky.us
HOMEPAGE=		http://www.gnucash.org/

DEPENDS+=		gnome-libs>=1.0.40:../../x11/gnome-libs
DEPENDS+=		gettext>=0.10.35:../../devel/gettext
DEPENDS+=		eperl-2.2.14:../../textproc/eperl
DEPENDS+=		libperl-5.00404:../../lang/libperl
DEPENDS+=		guile-1.3.*:../../lang/guile
DEPENDS+=		guile-slib-2c7:../../devel/guile-slib
DEPENDS+=		swig-1.1p5:../../devel/swig
DEPENDS+=		libxml>=1.8.5:../../textproc/libxml

USE_GMAKE=		# defined
USE_PERL=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/lib/g-wrap/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-guile-config=${LOCALBASE}/bin/guile-config
CONFIGURE_ARGS+=	--without-motif --without-included-gettext
CONFIGURE_ARGS+= \
    --with-perl-includes=${LOCALBASE}/lib/perl5/${MACHINE_ARCH}-netbsd/5.00404
CONFIGURE_ENV+=	"LOCALBASE=${LOCALBASE}"

ALL_TARGET=		gnome

.include "../../mk/bsd.pkg.mk"
