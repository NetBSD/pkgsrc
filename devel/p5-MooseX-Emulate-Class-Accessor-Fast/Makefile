# $NetBSD: Makefile,v 1.12 2013/05/31 12:40:32 wiz Exp $

DISTNAME=	MooseX-Emulate-Class-Accessor-Fast-0.00903
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Emulate-Class-Accessor-Fast/
COMMENT=	Emulate Class::Accessor::Fast behavior using Moose attributes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.84:../../devel/p5-Moose
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_PACKLIST=	auto/MooseX/Emulate/Class/Accessor/Fast/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
