# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:14 tv Exp $

PKGNAME=		postgresql74-plperl-${BASE_VERS}
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql74-server>=${BASE_VERS}:../../databases/postgresql74-server


.include "../postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile

PERL5_CONFIGURE=	NO

.include "../postgresql74-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/libperl/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
