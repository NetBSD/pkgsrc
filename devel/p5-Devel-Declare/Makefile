# $NetBSD: Makefile,v 1.44 2022/06/28 11:32:16 wiz Exp $

DISTNAME=	Devel-Declare-0.006022
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Declare
COMMENT=	Declarator magic for perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-B-Hooks-EndOfScope>0.05:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=		p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=		p5-ExtUtils-Depends>=0.302:../../devel/p5-ExtUtils-Depends

TEST_DEPENDS+=		p5-Devel-CallParser-[0-9]*:../../devel/p5-Devel-CallParser
TEST_DEPENDS+=		p5-B-Compiling-[0-9]*:../../devel/p5-B-Compiling # t/lines.t
TEST_DEPENDS+=		p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
TEST_DEPENDS+=		p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

USE_LANGUAGES=					c # is said redundant, but
PERL5_PACKLIST=					auto/Devel/Declare/.packlist
PERL5_MODULE_TYPE=				Module::Install::Bundled
BUILDLINK_DEPMETHOD.p5-B-Hooks-OP-Check=	full
BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=	p5-B-Hooks-OP-Check>=0.19

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
