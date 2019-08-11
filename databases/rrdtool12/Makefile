# $NetBSD: Makefile,v 1.23 2019/08/11 13:18:37 wiz Exp $

DISTNAME=	rrdtool-1.2.30
PKGREVISION=	15
CATEGORIES=	databases graphics net
MASTER_SITES=	https://oss.oetiker.ch/rrdtool/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oss.oetiker.ch/rrdtool/
COMMENT=	Data analysis tool generating graphical representations
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-perl-options=${MAKE_PARAMS:Q}
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby

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

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
