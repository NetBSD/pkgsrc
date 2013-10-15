# $NetBSD: Makefile,v 1.2 2013/10/15 02:15:44 wen Exp $

DISTNAME=	MooX-Options-3.90
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CE/CELOGEEK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~celogeek/MooX-Options/
COMMENT=	Perl module to add option keywords to your object (Mo/Moo/Moose)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Record-[0-9]*:../../devel/p5-Data-Record
DEPENDS+=	p5-Getopt-Long-Descriptive-[0-9]*:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-MooX-ConfigFromFile-[0-9]*:../../devel/p5-MooX-ConfigFromFile
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
BUILD_DEPENDS+=	p5-Role-Tiny-[0-9]*:../../devel/p5-Role-Tiny
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap
BUILD_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
BUILD_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
BUILD_DEPENDS+=	p5-Mo-[0-9]*:../../devel/p5-Mo
BUILD_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

PERL5_PACKLIST=		auto/MooX/Options/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
