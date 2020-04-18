# $NetBSD: Makefile,v 1.23 2020/04/18 01:19:07 mef Exp $

DISTNAME=	Specio-0.46
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Specio
COMMENT=	Type constraints and coercions for Perl
LICENSE=	artistic-2.0

DEPENDS+=	p5-Eval-Closure-[0-9]*:../../devel/p5-Eval-Closure
DEPENDS+=	p5-Role-Tiny>=1.003003:../../devel/p5-Role-Tiny
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Devel-StackTrace-[0-9]*:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Sub-Quote-[0-9]*:../../devel/p5-Sub-Quote
# recommended
DEPENDS+=	p5-Ref-Util-[0-9]*:../../devel/p5-Ref-Util

TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-XString-[0-9]*:../../devel/p5-XString

PERL5_PACKLIST=	auto/Specio/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
