# $NetBSD: Makefile,v 1.1.1.1 2009/10/02 09:59:40 hasso Exp $
#

.include "../../security/libpreludedb/Makefile.common"
.include "../../mk/bsd.prefs.mk"

PATCHDIR=		${.CURDIR}/../libpreludedb/patches
PKGNAME=		libpreludedb-perl-${VERSION}
COMMENT=		Perl bindings for LibPreludeDB libraries

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
