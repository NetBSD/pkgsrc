# $NetBSD: Makefile,v 1.21 2019/08/11 13:17:49 wiz Exp $
#

PKGNAME=		libpreludedb-perl-${VERSION}
PKGREVISION=		18
COMMENT=		Perl bindings for LibPreludeDB libraries

.include "../../security/libpreludedb/Makefile.common"

CONFIGURE_ARGS+=	--with-python=no
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-postgresql=no
CONFIGURE_ARGS+=	--with-sqlite3=no

BUILD_DIRS=		bindings

CONFIGURE_ARGS+=	--with-perl=${PERL5:Q} --with-perl-installdirs=vendor
USE_TOOLS+=		perl:run

PERL5_PACKLIST=		${PERL5_VENDORARCH}auto/PreludeDB/.packlist
PERL5_CONFIGURE=	no

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
