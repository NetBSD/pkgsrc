# $NetBSD: Makefile,v 1.28 2023/07/06 09:39:40 wiz Exp $

DISTNAME=	MooseX-Object-Pluggable-0.0014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Object-Pluggable
COMMENT=	Perl 5 module to add plugin support to Moose classes via roles
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
# for make test
TOOL_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Object/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
