# $NetBSD: Makefile,v 1.8 2002/10/27 19:41:53 seb Exp $
#

DISTNAME=		DBD-Sybase-0.94
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dsy
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.mbay.net/~mpeppler/
COMMENT=		perl DBI/DBD driver for Sybase/MS-SQL databases

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/Sybase/.packlist

PERL5_LDFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.freetds}/freetds/lib
MAKE_ENV+=		SYBASE=${BUILDLINK_PREFIX.freetds}/freetds

.include "../../databases/freetds/buildlink2.mk"
.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
