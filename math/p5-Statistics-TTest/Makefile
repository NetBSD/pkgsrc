# $NetBSD: Makefile,v 1.7 2019/08/11 13:21:52 wiz Exp $

DISTNAME=	Statistics-TTest-1.1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Statistics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Statistics-TTest
COMMENT=	Perl module of confidence interval computation using T-Tests
#LICENSE=	Unknown

DEPENDS+=	p5-Statistics-Descriptive>=2.6:../../math/p5-Statistics-Descriptive
DEPENDS+=	p5-Statistics-Distributions>=0.07:../../math/p5-Statistics-Distributions

PERL5_PACKLIST=		auto/Statistics/TTest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
