# $NetBSD: Makefile,v 1.10 2014/08/15 00:48:55 wen Exp $
#

DISTNAME=	MooseX-MultiInitArg-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-MultiInitArg/
COMMENT=	Attributes with aliases for constructor arguments
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/MultiInitArg/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
