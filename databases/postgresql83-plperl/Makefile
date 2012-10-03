# $NetBSD: Makefile,v 1.18 2012/10/03 21:54:25 wiz Exp $

PKGNAME=	${DISTNAME:C/-/83-plperl-/}
PKGREVISION=	1
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
