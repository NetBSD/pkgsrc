# $NetBSD: Makefile,v 1.22 2019/06/30 20:16:00 nia Exp $

DISTNAME=	TryCatch-1.003002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TryCatch
COMMENT=	First class try catch semantics for Perl, without source filters
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-B-Hooks-EndOfScope>=0.08:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-B-Hooks-OP-Check>=0.18:../../devel/p5-B-Hooks-OP-Check
DEPENDS+=	p5-B-Hooks-OP-PPAddr>=0.03:../../devel/p5-B-Hooks-OP-PPAddr
DEPENDS+=	p5-Devel-Declare>=0.005007:../../devel/p5-Devel-Declare
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Parse-Method-Signatures>=1.003012:../../devel/p5-Parse-Method-Signatures
DEPENDS+=	p5-Scope-Upper>=0.06:../../devel/p5-Scope-Upper
DEPENDS+=	p5-Sub-Exporter>=0.979:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Variable-Magic>=0.28:../../devel/p5-Variable-Magic

BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.302:../../devel/p5-ExtUtils-Depends
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/TryCatch/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../devel/p5-B-Hooks-OP-PPAddr/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
