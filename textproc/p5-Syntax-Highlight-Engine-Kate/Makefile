# $NetBSD: Makefile,v 1.26 2023/07/06 09:41:48 wiz Exp $

DISTNAME=	Syntax-Highlight-Engine-Kate-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Syntax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Syntax-Highlight-Engine-Kate
COMMENT=	Perl port of the syntax highlight engine of the Kate texteditor
LICENSE=	${PERL5_LICENSE}

CHECK_PORTABILITY_SKIP=	samples/highlight.sh

DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny

# TEST_DEPENDS
TOOL_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
TOOL_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff
TOOL_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Syntax/Highlight/Engine/Kate/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
