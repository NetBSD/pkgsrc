# $NetBSD: Makefile,v 1.7 2019/06/30 20:15:22 nia Exp $

DISTNAME=	Moos-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Moos
COMMENT=	Moo s{imple,peedy,ingle}
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-XSAccessor>=1.07:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-Role-Tiny>=1.002.000:../../devel/p5-Role-Tiny

BUILD_DEPENDS+=	p5-namespace-autoclean>=0:../../devel/p5-namespace-autoclean

REPLACE_PERL=	bin/remoos

PERL5_PACKLIST=	auto/Moos/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
