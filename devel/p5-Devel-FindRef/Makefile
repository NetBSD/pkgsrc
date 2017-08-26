# $NetBSD: Makefile,v 1.14 2017/08/26 05:20:50 mef Exp $

DISTNAME=	Devel-FindRef-1.45
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-FindRef/
COMMENT=	Perl 5 module to track down references
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense
DEPENDS+=	p5-Canary-Stability-[0-9]*:../../devel/p5-Canary-Stability

PERL5_PACKLIST=		auto/Devel/FindRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
