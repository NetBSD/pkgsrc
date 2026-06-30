# $NetBSD: Makefile,v 1.48 2026/06/30 19:43:36 wiz Exp $

DISTNAME=	Devel-NYTProf-6.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-NYTProf
COMMENT=	Powerful feature-rich Perl 5 source code profiler
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=		p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=		p5-File-Which-[0-9]*:../../devel/p5-File-Which
TEST_DEPENDS+=		p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
TEST_DEPENDS+=		p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
TEST_DEPENDS+=		p5-Sub-Name>=0.11:../../devel/p5-Sub-Name
TEST_DEPENDS+=		p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.PL
SUBST_VARS.paths=	PREFIX

PERL5_PACKLIST=		auto/Devel/NYTProf/.packlist
REPLACE_PERL+=		lib/Devel/NYTProf/FileHandle.pm

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
