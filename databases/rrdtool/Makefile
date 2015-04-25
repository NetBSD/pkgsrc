# $NetBSD: Makefile,v 1.117 2015/04/25 14:20:31 tnn Exp $
#
# Please, also update databases/ruby-rrdtool

DISTNAME=	rrdtool-1.4.9
PKGREVISION=	1
CATEGORIES=	databases graphics net
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oss.oetiker.ch/rrdtool/
COMMENT=	Data analysis tool generating graphical representations
LICENSE=	gnu-gpl-v2

DEPENDS+=		dejavu-ttf>=2.26:../../fonts/dejavu-ttf

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config perl msgfmt intltool groff nroff
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-perl-options=${MAKE_PARAMS:Q}
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--disable-libdbi

PTHREAD_OPTS+=		require
PERL5_CONFIGURE=	no
PERL5_PACKLIST+=	auto/RRDp/.packlist
PERL5_PACKLIST+=	auto/RRDs/.packlist

# rrdtool explicitly forbids any use of -ffast-math
BUILDLINK_TRANSFORM+=	rm:-ffast-math

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-build
SUBST_MESSAGE.prefix=	Fixing $${prefix} in scripts.
SUBST_FILES.prefix=	examples/cgi-demo.cgi
SUBST_SED.prefix=	-e '1s,^\#! \$${prefix},\#! ${PREFIX},'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
