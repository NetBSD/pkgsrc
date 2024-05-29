# $NetBSD: Makefile,v 1.5 2024/05/29 16:31:51 adam Exp $

PKGNAME=	${DISTNAME:S/-/16-plperl-/}
PKGREVISION=	1
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql16-server>=${PKGVERSION_NOREV}:../../databases/postgresql16-server

.include "../../databases/postgresql16/Makefile.common"

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile

# There is some dependency ordering problem in the Makefile,
# so force the headers to be generated first.
BUILD_TARGET=		perlchunks.h plperl_opmask.h all

.include "../../databases/postgresql16-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
