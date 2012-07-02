# $NetBSD: Makefile,v 1.15.2.1 2012/07/02 23:06:55 tron Exp $

PKGNAME=	${DISTNAME:C/-/83-plperl-/}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

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
