# $NetBSD: Makefile,v 1.15 2015/06/12 10:49:53 wiz Exp $

DISTNAME=	Throwable-0.200012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Throwable/
COMMENT=	Perl 5 role for classes that can be thrown
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-StackTrace>=1.2100:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Moo>=1.000001:../../devel/p5-Moo

PERL5_PACKLIST=		auto/Throwable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
