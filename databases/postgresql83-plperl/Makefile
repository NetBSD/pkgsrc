# $NetBSD: Makefile,v 1.9 2010/12/19 09:53:53 adam Exp $

PKGNAME=	${DISTNAME:C/-/83-plperl-/}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql83-server>=${PKGVERSION}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

USE_TOOLS+=		perl
USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile
BUILD_MAKE_FLAGS=	PGXS=1

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
