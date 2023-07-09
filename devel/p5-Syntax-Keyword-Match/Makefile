# $NetBSD: Makefile,v 1.3 2023/07/09 14:38:46 nia Exp $

DISTNAME=	Syntax-Keyword-Match-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Syntax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Syntax::Keyword::Match
COMMENT=	Perl5 module to provide a match/case syntax
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XS-Parse-Keyword>=0.23:../../devel/p5-XS-Parse-Keyword

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=	c99

PERL5_PACKLIST=		auto/Syntax/Keyword/Match/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
