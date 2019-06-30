# $NetBSD: Makefile,v 1.23 2019/06/30 20:16:35 nia Exp $

DISTNAME=	LaTeX-Driver-0.300.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LaTeX-Driver
COMMENT=	Perl module encapsulates the details of invoking the Latex programs
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	gs:run

DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
DEPENDS+=	p5-Module-Install-ReadmeFromPod-[0-9]*:../../devel/p5-Module-Install-ReadmeFromPod
DEPENDS+=	p5-Module-Install-AuthorRequires-[0-9]*:../../devel/p5-Module-Install-AuthorRequires
DEPENDS+=	p5-Module-Install-AuthorTests-[0-9]*:../../devel/p5-Module-Install-AuthorTests
DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
DEPENDS+=	p5-Test-NoTabs-[0-9]*:../../devel/p5-Test-NoTabs
DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
DEPENDS+=	p5-Test-Spelling-[0-9]*:../../devel/p5-Test-Spelling
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-IO-All>=0:../../devel/p5-IO-All
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-lastpage-[0-9]*:../../print/tex-lastpage
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk

# for make test
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
# t/20-complexdoc.t requires following package
BUILD_DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex

# xelatex is necessary for FORMATTER_TESTING
#EST_ENV+=	FORMATTER_TESTING=yes
TEST_ENV+=	BIBTEX_TESTS=yes

PERL5_MODULE_TYPE=	Module::Install
PERL5_PACKLIST=		auto/LaTeX/Driver/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
