# $NetBSD: Makefile,v 1.14 2017/06/05 14:23:22 ryoon Exp $

DISTNAME=	MooseX-Types-LoadableClass-0.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-LoadableClass/
COMMENT=	Moose ClassName type constraint with coercion to load the class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0.06:../../devel/p5-Class-Load
DEPENDS+=	p5-Moose>=2:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.22:../../devel/p5-MooseX-Types
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Types/LoadableClass/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
