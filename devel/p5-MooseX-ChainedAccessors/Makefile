# $NetBSD: Makefile,v 1.4 2013/05/31 12:40:32 wiz Exp $
#

DISTNAME=	MooseX-ChainedAccessors-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-ChainedAccessors/
COMMENT=	Accessor class for chained accessors with Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/MooseX/ChainedAccessors/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
