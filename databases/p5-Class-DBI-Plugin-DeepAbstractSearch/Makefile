# $NetBSD: Makefile,v 1.13 2018/08/22 09:43:14 wiz Exp $
#

DISTNAME=	Class-DBI-Plugin-DeepAbstractSearch-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Class::DBI::Plugin::DeepAbstractSearch
COMMENT=	Implement deep_search_where() for Class::DBI

DEPENDS+=	p5-Class-DBI>=0.96:../../databases/p5-Class-DBI
DEPENDS+=	p5-Class-DBI-Plugin>=0.02:../../databases/p5-Class-DBI-Plugin
DEPENDS+=	p5-SQL-Abstract>=1.18:../../databases/p5-SQL-Abstract
#BUILD_DEPENDS+=	{perl>=5.6.2,p5-Test-Simple>=0.32}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Class/DBI/Plugin/DeepAbstractSearch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
