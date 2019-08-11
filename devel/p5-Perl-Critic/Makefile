# $NetBSD: Makefile,v 1.39 2019/08/11 13:20:10 wiz Exp $
#

DISTNAME=	Perl-Critic-1.134
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Perl-Critic
COMMENT=	Perl 5 module providing a static Perl source code analysis engine
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL=	lib/Test/Perl/Critic/Policy.pm

DEPENDS+=	p5-B-Keywords>=1.05:../../devel/p5-B-Keywords
DEPENDS+=	p5-Config-Tiny>=2:../../devel/p5-Config-Tiny
DEPENDS+=	p5-Exception-Class>=1.23:../../devel/p5-Exception-Class
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-List-MoreUtils>=0.19:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Module-Pluggable>=3.1:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-PPI>=1.265:../../devel/p5-PPI
DEPENDS+=	p5-PPIx-QuoteLike>=0:../../textproc/p5-PPIx-QuoteLike
DEPENDS+=	p5-PPIx-Regexp>=0.022:../../devel/p5-PPIx-Regexp
DEPENDS+=	p5-PPIx-Utilities>=1.001:../../devel/p5-PPIx-Utilities
DEPENDS+=	p5-Perl-Tidy-[0-9]*:../../devel/p5-Perl-Tidy
DEPENDS+=	p5-Pod-Spell>=1:../../textproc/p5-Pod-Spell
DEPENDS+=	p5-Readonly>=2.0:../../devel/p5-Readonly
DEPENDS+=	p5-String-Format>=1.13:../../devel/p5-String-Format
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable

# Recommended dependencies
DEPENDS+=	p5-Readonly-XS-[0-9]*:../../devel/p5-Readonly-XS
#DEPENDS+=	p5-Regexp-Parser>=0.20:../../devel/p5-Regexp-Parser

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl/Critic/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
