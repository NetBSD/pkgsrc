# $NetBSD: Makefile,v 1.1.1.1 2007/04/22 21:02:25 seb Exp $
#

DISTNAME=	Module-Starter-PBP-v0.0.3
PKGNAME=	p5-Module-Starter-PBP-0.0.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Starter-PBP/
COMMENT=	Perl 5 module plugin for Module::Starter module

DEPENDS+=	p5-Module-Starter-[0-9]*:../../devel/p5-Module-Starter
DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Starter/PBP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
