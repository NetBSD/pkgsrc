# $NetBSD: Makefile,v 1.13 2004/04/27 05:44:22 snj Exp $

PKGNAME=		postgresql-plperl-${BASE_VERS}
PKGREVISION=		2
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=		postgresql-server>=${BASE_VERS}:../../databases/postgresql-server

USE_BUILDLINK3=		yes

.include "../postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ENV+=		PERL="${PERL5}"

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile

.include "../postgresql-lib/buildlink3.mk"
.include "../../lang/libperl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
