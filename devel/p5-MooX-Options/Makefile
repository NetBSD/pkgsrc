# $NetBSD: Makefile,v 1.27 2022/06/28 11:32:50 wiz Exp $

DISTNAME=	MooX-Options-4.103
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CELOGEEK/MooX-Options-4.023
COMMENT=	Perl module to add option keywords to your object (Mo/Moo/Moose)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Record-[0-9]*:../../devel/p5-Data-Record
DEPENDS+=	p5-Getopt-Long-Descriptive>=0.099:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moo>=2.002002:../../devel/p5-Moo
# used in tests; cannot depend on it since it depends on us
#DEPENDS+=	p5-MooX-Cmd-[0-9]*:../../devel/p5-MooX-Cmd
DEPENDS+=	p5-MooX-ConfigFromFile-[0-9]*:../../devel/p5-MooX-ConfigFromFile
DEPENDS+=	p5-Path-Class>=0.32:../../devel/p5-Path-Class
DEPENDS+=	p5-Term-Size-Any-[0-9]*:../../devel/p5-Term-Size-Any
DEPENDS+=	p5-Unicode-LineBreak-[0-9]*:../../textproc/p5-Unicode-LineBreak
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-MooX-Locale-Passthrough>=0:../../devel/p5-MooX-Locale-Passthrough

BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-Role-Tiny-[0-9]*:../../devel/p5-Role-Tiny
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap
BUILD_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
BUILD_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
BUILD_DEPENDS+=	p5-Mo-[0-9]*:../../devel/p5-Mo
BUILD_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

PERL5_PACKLIST=		auto/MooX/Options/.packlist
#PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
