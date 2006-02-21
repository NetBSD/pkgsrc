# $NetBSD: Makefile,v 1.9 2006/02/21 20:23:49 joerg Exp $

PKGNAME=		postgresql74-plperl-${BASE_VERS}
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql74-server>=${BASE_VERS}:../../databases/postgresql74-server


.include "../../databases/postgresql74/Makefile.common"

PERL5_CONFIGURE=	NO
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile

.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
