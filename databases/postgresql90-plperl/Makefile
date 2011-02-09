# $NetBSD: Makefile,v 1.3 2011/02/09 08:48:19 adam Exp $

PKGNAME=	${DISTNAME:C/-/90-plperl-/}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

#USE_LIBTOOL=		yes
#PKG_LIBTOOL=		${PKG_SHLIBTOOL}
USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
