# $NetBSD: Makefile,v 1.1.1.1 2004/07/24 22:18:51 recht Exp $

PKGNAME=		postgresql73-plperl-${BASE_VERS}
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql73-server>=${BASE_VERS}:../../databases/postgresql73-server

USE_BUILDLINK3=		yes

.include "../postgresql73/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ENV+=		PERL="${PERL5}"

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile

.include "../postgresql73-lib/buildlink3.mk"
.include "../../lang/libperl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
