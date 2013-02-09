# $NetBSD: Makefile,v 1.22 2013/02/09 11:19:09 adam Exp $

PKGNAME=	${DISTNAME:C/-/83-plperl-/}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		src/pl/plperl
BUILD_MAKE_FLAGS=	PGXS=1
MAKE_FILE=		GNUmakefile

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
