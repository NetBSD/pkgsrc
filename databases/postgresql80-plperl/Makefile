# $NetBSD: Makefile,v 1.2 2005/09/19 05:52:18 jlam Exp $

PKGNAME=	postgresql80-plperl-${BASE_VERS}
PKGREVISION=	1
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql80-server>=${BASE_VERS}:../../databases/postgresql80-server

.include "../../databases/postgresql80/Makefile.common"

PERL5_CONFIGURE=	NO
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql80-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
