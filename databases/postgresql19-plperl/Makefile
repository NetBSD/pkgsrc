# $NetBSD: Makefile,v 1.1 2026/11/24 19:22:52 adam Exp $

PKGNAME=	${DISTNAME:S/-/19-plperl-/}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql19-server>=${PKGVERSION_NOREV}:../../databases/postgresql19-server

.include "../../databases/postgresql19/Makefile.common"

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile

# There is some dependency ordering problem in the Makefile,
# so force the headers to be generated first.
BUILD_TARGET=		perlchunks.h plperl_opmask.h all

.include "../../databases/postgresql19-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
