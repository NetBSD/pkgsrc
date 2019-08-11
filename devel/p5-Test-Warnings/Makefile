# $NetBSD: Makefile,v 1.18 2019/08/11 13:20:38 wiz Exp $

DISTNAME=	Test-Warnings-0.026
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Warnings
COMMENT=	Test for warnings and the lack of them
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS=	p5-CPAN-Meta-Check>=0.007:../../devel/p5-CPAN-Meta-Check
# for make test
BUILD_DEPENDS+=	p5-Module-Metadata>=1.000023:../../devel/p5-Module-Metadata

PERL5_PACKLIST=		auto/Test/Warnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
