# $NetBSD: Makefile,v 1.5 2024/01/04 11:14:03 wiz Exp $

DISTNAME=	Syntax-Keyword-Match-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Syntax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Syntax::Keyword::Match
COMMENT=	Perl5 module to provide a match/case syntax
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XS-Parse-Keyword>=0.36:../../devel/p5-XS-Parse-Keyword
TEST_DEPENDS+=	p5-Test2-Suite>=0:../../devel/p5-Test2-Suite

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

PERL5_PACKLIST=		auto/Syntax/Keyword/Match/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
