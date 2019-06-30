# $NetBSD: Makefile,v 1.16 2019/06/30 20:14:57 nia Exp $

DISTNAME=	Dist-Zooky-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Dist-Zooky
COMMENT=	Perl 5 module to convert a distribution to Dist::Zilla
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-App-Cmd>=0.307:../../devel/p5-App-Cmd
#DEPENDS+=	{perl>=5.16.0,p5-CPAN-Meta>=2.101610}:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-Dist-Zilla>=4.102342:../../devel/p5-Dist-Zilla
#DEPENDS+=	{perl>=5.11.3,p5-ExtUtils-MakeMaker>=6.56}:../../devel/p5-ExtUtils-MakeMaker
#DEPENDS+=	{perl>=5.13.3,p5-Module-Build>=0.36070}:../../devel/p5-Module-Build
DEPENDS+=	p5-Moose>=1.07:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.22:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Perl>=0.101340:../../devel/p5-MooseX-Types-Perl
DEPENDS+=	p5-Software-License>=0.101.620:../../devel/p5-Software-License

# for implicit depdendencies like File::Temp, IPC::Cmd,
#     Module::Load::Conditional, Params::Check
PERL5_REQD+=	5.14.1

PERL5_PACKLIST=		auto/Dist/Zooky/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
