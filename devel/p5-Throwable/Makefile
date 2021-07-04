# $NetBSD: Makefile,v 1.24 2021/07/04 07:45:49 wen Exp $

DISTNAME=	Throwable-1.000
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Throwable
COMMENT=	Perl 5 role for classes that can be thrown
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-StackTrace>=1.2100:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Moo>=1.000001:../../devel/p5-Moo

PERL5_PACKLIST=		auto/Throwable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
