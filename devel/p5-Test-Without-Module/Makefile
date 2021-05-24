# $NetBSD: Makefile,v 1.12 2021/05/24 19:51:51 wiz Exp $

DISTNAME=	Test-Without-Module-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Without-Module
COMMENT=	Perl 5 module to fallback test behaviour in absence of modules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Without/Module/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
