# $NetBSD: Makefile,v 1.7 2017/11/21 15:18:23 fhajny Exp $

PKGNAME=		p5-${DISTNAME}
COLLECTD_PACKAGE=	perl

COMMENT=		Statistics collection daemon - perl plugin

.include "../../sysutils/collectd/Makefile.common"

USE_TOOLS+=		perl

PERL5_CONFIGURE=	no
PERL5_PACKLIST+=	auto/Collectd/.packlist

CONFIGURE_ARGS+=	--with-libperl=${BUILDLINK_PREFIX.perl}
CONFIGURE_ARGS+=	--with-perl-bindings=${MAKE_PARAMS:Q}

BUILD_TARGET+=		perl
INSTALL_TARGET+=	install-exec-local

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
