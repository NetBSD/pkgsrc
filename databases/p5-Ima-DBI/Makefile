# $NetBSD: Makefile,v 1.2 2004/11/12 17:36:40 seb Exp $
#

DISTNAME=		Ima-DBI-0.33
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5idi
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/T/TM/TMTM/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Ima-DBI/
COMMENT=		Perl5 module for DB connection caching and organization

DEPENDS+=		p5-DBI>=1.20:../../databases/p5-DBI
DEPENDS+=		p5-Class-WhiteHole>=0.03:../../devel/p5-Class-WhiteHole
DEPENDS+=		p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Ima/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
