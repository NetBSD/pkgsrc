# $NetBSD: Makefile,v 1.10 2012/10/31 11:18:38 asau Exp $

DISTNAME=	MooseX-SimpleConfig-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-SimpleConfig/
COMMENT=	Moose role for setting attributes from a simple configfile
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-Any>=0.13:../../devel/p5-Config-Any
DEPENDS+=	p5-Moose>=0.35:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-ConfigFromFile>=0.02:../../devel/p5-MooseX-ConfigFromFile

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/MooseX/SimpleConfig/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
