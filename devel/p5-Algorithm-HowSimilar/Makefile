# $NetBSD: Makefile,v 1.17 2023/07/06 09:38:34 wiz Exp $

DISTNAME=	Algorithm-HowSimilar-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-HowSimilar
COMMENT=	Perl module for computation of similarity amongst values
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Algorithm-Diff>=1.0:../../devel/p5-Algorithm-Diff

PERL5_PACKLIST=		auto/Algorithm/HowSimilar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
