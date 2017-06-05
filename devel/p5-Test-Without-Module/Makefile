# $NetBSD: Makefile,v 1.7 2017/06/05 14:23:48 ryoon Exp $

DISTNAME=	Test-Without-Module-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Without-Module/
COMMENT=	Perl 5 module to fallback test behaviour in absence of modules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Without/Module/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
