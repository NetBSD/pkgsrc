# $NetBSD: Makefile,v 1.3 2006/09/09 02:41:56 obache Exp $

PKGNAME=	postgresql81-plperl-${BASE_VERS}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

.include "../../databases/postgresql81/Makefile.common"

PERL5_CONFIGURE=	NO
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKE_FILE=		GNUmakefile

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql81-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
