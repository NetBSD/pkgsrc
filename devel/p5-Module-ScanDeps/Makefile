# $NetBSD: Makefile,v 1.57 2023/12/18 13:35:44 mef Exp $

DISTNAME=	Module-ScanDeps-1.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-ScanDeps
COMMENT=	Perl 5 module to recursively scan Perl code for dependencies
LICENSE=	${PERL5_LICENSE}

# TEST_DEPENDS
TOOL_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TOOL_DEPENDS+=	p5-prefork-[0-9]*:../../devel/p5-prefork

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/ScanDeps/.packlist

REPLACE_PERL+=	script/scandeps.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
