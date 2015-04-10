# $NetBSD: Makefile,v 1.11 2015/04/10 01:03:20 mef Exp $
#

DISTNAME=	Lexical-SealRequireHints-0.009
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lexical/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lexical-SealRequireHints/
COMMENT=	Perl5 module to prevent leakage of lexical hints
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Lexical/SealRequireHints/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
