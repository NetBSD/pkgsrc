# $NetBSD: Makefile,v 1.2 2004/11/12 17:36:40 seb Exp $
#

DISTNAME=	Class-DBI-0.96
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdi
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI/
COMMENT=	Perl5 module for Simple Database Abstraction

DEPENDS+=	p5-Class-Accessor>=0.18:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Trigger>=0.07:../../devel/p5-Class-Trigger
DEPENDS+=	p5-File-Temp>=0.12:../../devel/p5-File-Temp
DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
DEPENDS+=	p5-Ima-DBI>=0.33:../../databases/p5-Ima-DBI
DEPENDS+=	p5-UNIVERSAL-moniker>=0.06:../../devel/p5-UNIVERSAL-moniker

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
