# $NetBSD: Makefile,v 1.3 2019/08/11 13:21:51 wiz Exp $

DISTNAME=	Statistics-CaseResampling-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Statistics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Statistics-CaseResampling
COMMENT=	Efficient resampling and calculation of medians with confidence intervals
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Statistics/CaseResampling/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
