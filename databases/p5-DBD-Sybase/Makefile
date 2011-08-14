# $NetBSD: Makefile,v 1.33 2011/08/14 08:18:05 obache Exp $
#

DISTNAME=		DBD-Sybase-1.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
SVR4_PKGNAME=		p5dsy
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.peppler.org/freeware/dbd-sybase.html
COMMENT=		Perl DBI/DBD driver for Sybase/MS-SQL databases
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/DBD/Sybase/.packlist

BUILD_DEFS+=		USE_SYBASE_OPENCLIENT
BUILD_DEFS+=		SYBASE

.if defined(USE_SYBASE_OPENCLIENT) && empty(USE_SYBASE_OPENCLIENT:M[Nn][Oo])
.  if defined(SYBASE) || exists(${SYBASE}/lib/libct.so)
BUILDLINK_PASSTHRU_DIRS=${SYBASE}
_SYBASE=		${SYBASE}
.  else
PKG_FAIL_REASON+=	"You must define SYBASE to the base directory of your Open Client."
.  endif
.else
_SYBASE=		${BUILDLINK_PREFIX.freetds}
.endif

PERL5_LDFLAGS+=		${COMPILER_RPATH_FLAG}${_SYBASE}/lib
MAKE_ENV+=		SYBASE=${_SYBASE:Q}
MAKE_PARAMS+=		--accept_test_defaults
MAKE_PARAMS+=		--chained Y

.if !defined(USE_SYBASE_OPENCLIENT)
.  include "../../databases/freetds/buildlink3.mk"
.endif

.include "../../lang/perl5/module.mk"

.if !empty(PKG_BUILD_OPTIONS.perl:Mthreads)
MAKE_PARAMS+=		--threaded_libs Y
.else
MAKE_PARAMS+=		--threaded_libs N
.endif

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
