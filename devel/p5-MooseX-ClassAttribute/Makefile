# $NetBSD: Makefile,v 1.15 2013/05/31 12:40:32 wiz Exp $
#

DISTNAME=	MooseX-ClassAttribute-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-ClassAttribute/
COMMENT=	Perl 5 module to declare class attributes Moose-style
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/ClassAttribute/.packlist

DEPENDS+=	p5-Moose>=1.23:../../devel/p5-Moose
DEPENDS+=	p5-namespace-autoclean>=0.11:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
