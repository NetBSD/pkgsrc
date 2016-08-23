# $NetBSD: Makefile,v 1.15 2016/08/23 06:28:15 adam Exp $

PKGNAME=	${DISTNAME:C/-/92-plperl-/}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql92-server>=${PKGVERSION_NOREV}:../../databases/postgresql92-server

.include "../../databases/postgresql92/Makefile.common"

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
