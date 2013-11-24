# $NetBSD: Makefile,v 1.8 2013/11/24 04:12:59 wen Exp $
#

DISTNAME=	Mixin-Linewise-0.102
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mixin-Linewise/
COMMENT=	Perl 5 linewise readers and writers for strings and filenames
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Sub-Exporter>=0.900:../../devel/p5-Sub-Exporter

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mixin/Linewise/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
