# $NetBSD: Makefile,v 1.10 2003/11/12 03:39:39 jschauma Exp $

PKGNAME=		postgresql-plperl-${BASE_VERS}
PKGREVISION=		1
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=		postgresql-server>=${BASE_VERS}:../../databases/postgresql-server

.include "../postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ENV+=		PERL="${PERL5}"

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile

.include "../postgresql-lib/buildlink2.mk"
.include "../../lang/libperl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
