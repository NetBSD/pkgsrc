# $NetBSD: Makefile,v 1.8 2013/05/31 12:40:27 wiz Exp $
#

DISTNAME=	Lexical-SealRequireHints-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
