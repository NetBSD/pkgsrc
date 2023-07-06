# $NetBSD: Makefile,v 1.9 2023/07/06 09:41:53 wiz Exp $

DISTNAME=	Text-MultiMarkdown-1.000035
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BO/BOBTFISH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-MultiMarkdown
COMMENT=	Convert MultiMarkdown syntax to (X)HTML
LICENSE=	modified-bsd

TOOL_DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install
DEPENDS+=	p5-Text-Markdown>=1.0.26:../../textproc/p5-Text-Markdown
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=	auto/Text/MultiMarkdown/.packlist
USE_LANGUAGES=	# none

REPLACE_PERL+=	script/MultiMarkdown.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
