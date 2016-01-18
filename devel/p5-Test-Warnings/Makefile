# $NetBSD: Makefile,v 1.12 2016/01/18 13:35:57 wen Exp $

DISTNAME=	Test-Warnings-0.024
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Warnings/
COMMENT=	Test for warnings and the lack of them
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS=	p5-CPAN-Meta-Check>=0.007:../../devel/p5-CPAN-Meta-Check
# for make test
BUILD_DEPENDS+=	p5-Module-Metadata>=1.000023:../../devel/p5-Module-Metadata

PERL5_PACKLIST=		auto/Test/Warnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
