# $NetBSD: Makefile,v 1.17 2019/06/30 20:14:54 nia Exp $

DISTNAME=	Devel-FindRef-1.46
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-FindRef
COMMENT=	Perl 5 module to track down references
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense
DEPENDS+=	p5-Canary-Stability-[0-9]*:../../devel/p5-Canary-Stability

PERL5_PACKLIST=		auto/Devel/FindRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
