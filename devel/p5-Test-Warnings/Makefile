# $NetBSD: Makefile,v 1.25 2022/06/28 11:33:31 wiz Exp $

DISTNAME=	Test-Warnings-0.031
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Warnings
COMMENT=	Test for warnings and the lack of them
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS=	p5-CPAN-Meta-Check>=0.007:../../devel/p5-CPAN-Meta-Check

PERL5_PACKLIST=		auto/Test/Warnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
