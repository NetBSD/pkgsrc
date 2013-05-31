# $NetBSD: Makefile,v 1.10 2013/05/31 12:40:32 wiz Exp $

DISTNAME=	MooseX-ConfigFromFile-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-ConfigFromFile/
COMMENT=	Abstract Moose role for setting attributes from a configfile
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.35:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-Path-Class>=0.04:../../devel/p5-MooseX-Types-Path-Class
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/MooseX/ConfigFromFile/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
