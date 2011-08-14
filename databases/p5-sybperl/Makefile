# $NetBSD: Makefile,v 1.19 2011/08/14 08:18:11 obache Exp $
#

DISTNAME=	sybperl-2.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.peppler.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.peppler.org/freeware/sybperl.html
COMMENT=	Perl modules for using Sybase/MS-SQL databases

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Sybase/.packlist

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

.if !defined(USE_SYBASE_OPENCLIENT)
.  include "../../databases/freetds/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
