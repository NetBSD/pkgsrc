# $NetBSD: Makefile,v 1.7 2008/06/20 08:27:58 adam Exp $

PKGNAME=	postgresql81-plperl-${BASE_VERS}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

.include "../../databases/postgresql81/Makefile.common"

PERL5_CONFIGURE=	NO
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile
BUILD_MAKE_FLAGS=	PGXS=1

USE_TOOLS+=		perl
USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql81-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
