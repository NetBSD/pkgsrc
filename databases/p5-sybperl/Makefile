# $NetBSD: Makefile,v 1.1.1.1 2004/03/29 10:01:33 grant Exp $
#

DISTNAME=	sybperl-2.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.peppler.org/downloads/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.mbay.net/~mpeppler/
COMMENT=	Perl modules for using Sybase/MS-SQL databases

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sybase/.packlist

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
_SYBASE=		${BUILDLINK_PREFIX.freetds}/freetds
.endif

PERL5_LDFLAGS+=		-Wl,${RPATH_FLAG}${_SYBASE}/lib
MAKE_ENV+=		SYBASE=${_SYBASE}

.if !defined(USE_SYBASE_OPENCLIENT)
.  include "../../databases/freetds/buildlink2.mk"
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
