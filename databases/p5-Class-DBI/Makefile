# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:06 jlam Exp $
#

DISTNAME=	Class-DBI-0.96
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdi
PKGREVISION=	2
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

PERL5_PACKLIST=	auto/Class/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
