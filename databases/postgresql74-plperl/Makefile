# $NetBSD: Makefile,v 1.1.1.1 2004/10/10 12:24:10 jdolecek Exp $

PKGNAME=		postgresql74-plperl-${BASE_VERS}
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql74-server>=${BASE_VERS}:../../databases/postgresql74-server

USE_BUILDLINK3=		yes

.include "../postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-perl

LIBPERL_DIR=		${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}/CORE
LDFLAGS+=		-Wl,-R${LIBPERL_DIR}

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile

PERL5_CONFIGURE=	NO

# On my 2.x system perl 5.8.4's perl & libperl.so are linked with libpthread,
# thus the module would get linked to libpthread too. Since postmaster is not
# threaded, loading the language will crash the SQL server.
BROKEN=			"crashes PostgreSQL when compiled with threaded Perl"

# XXX this package requires modification of the link flags to add the
# directory with libperl.so to the runtime library search path. Since
# this is currently broken anyway, appropriate patch for src/Makefile.global.in
# has not been included.

.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.libperl+=	build
.include "../postgresql74-lib/buildlink3.mk"
.include "../../lang/libperl/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
