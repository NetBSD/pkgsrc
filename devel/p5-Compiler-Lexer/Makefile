# $NetBSD: Makefile,v 1.5 2023/06/06 12:40:44 riastradh Exp $

DISTNAME=	Compiler-Lexer-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compiler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Compiler-Lexer
COMMENT=	Lexical Analyzer for Perl5
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Module-Build-XSUtil-[0-9]*:../../devel/p5-Module-Build-XSUtil

USE_LANGUAGES=		c c++
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Compiler/Lexer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
