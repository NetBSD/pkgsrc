# $NetBSD: Makefile,v 1.7 2012/12/16 01:52:06 obache Exp $

PKGNAME=	${DISTNAME:C/-/91-plperl-/}
PKGREVISION=	1
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
