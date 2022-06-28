# $NetBSD: Makefile,v 1.29 2022/06/28 11:35:36 wiz Exp $

PKGNAME=		libprelude-perl-${VERSION}
PKGREVISION=		26
COMMENT=		Perl bindings to LibPrelude

.include "../../security/libprelude/Makefile.common"

CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-perl-installdirs=vendor
USE_TOOLS+=		perl:run
PERL5_PACKLIST=		auto/Prelude/.packlist
PERL5_PACKLIST+=	auto/PreludeEasy/.packlist
PERL5_CONFIGURE=	no
# something overrides USE_LANGUAGES from Makefile.common so repeat this here
USE_LANGUAGES=		c c++

.include "../../lang/perl5/module.mk"

PLIST_SRC=

BUILD_DIRS=		bindings/low-level/perl bindings/perl

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS=			-O0 -ggdb
.endif

do-build:
	cd ${WRKSRC}/bindings && ${MAKE} perl-build
	cd ${WRKSRC}/bindings/low-level && ${MAKE} perl-build

.include "../../devel/libltdl/convenience.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../security/libprelude/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
