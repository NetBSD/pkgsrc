# $NetBSD: Makefile,v 1.30 2018/08/22 09:44:45 wiz Exp $

DISTNAME=		Test-Exception-0.43
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Exception/
COMMENT=		Test exception based code
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Sub-Uplevel>=0.18:../../devel/p5-Sub-Uplevel

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Exception/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
