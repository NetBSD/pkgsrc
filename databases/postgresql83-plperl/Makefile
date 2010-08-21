# $NetBSD: Makefile,v 1.7 2010/08/21 16:33:08 seb Exp $

PKGNAME=	postgresql83-plperl-${BASE_VERS}
PKGREVISION=	1
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql83-server>=${BASE_VERS}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile
BUILD_MAKE_FLAGS=	PGXS=1

USE_TOOLS+=		perl
USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
