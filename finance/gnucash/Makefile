# $NetBSD: Makefile,v 1.1.1.1 2000/12/11 13:53:26 wiz Exp $
#

DISTNAME=		gnucash-1.4.8
CATEGORIES=		finance
MASTER_SITES=		http://www.linas.org/pub/gnucash/gnucash/sources/stable/ \
			ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		drankin@bohemians.lexington.ky.us
HOMEPAGE=		http://www.gnucash.org/

DEPENDS+=		gnome-libs>=1.0.40:../../x11/gnome-libs
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=		eperl-2.2.14:../../textproc/eperl
DEPENDS+=		g-wrap>=0.9.5:../../devel/g-wrap
DEPENDS+=		guile-slib-2c8:../../devel/guile-slib
DEPENDS+=		libperl-5.*:../../lang/libperl
DEPENDS+=		swig-1.1p5:../../devel/swig
DEPENDS+=		libxml>=1.8.7:../../textproc/libxml

USE_GMAKE=		# defined
USE_PERL5=		# defined
USE_X11=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE+=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-guile-config=${LOCALBASE}/bin/guile-config
CONFIGURE_ARGS+=	--without-motif --without-included-gettext
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}

CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
