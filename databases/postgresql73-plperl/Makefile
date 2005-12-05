# $NetBSD: Makefile,v 1.7 2005/12/05 20:49:58 rillig Exp $

PKGNAME=		postgresql73-plperl-${BASE_VERS}
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql73-server>=${BASE_VERS}:../../databases/postgresql73-server


.include "../../databases/postgresql73/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile

.include "../../databases/postgresql73-lib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
