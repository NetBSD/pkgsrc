# $NetBSD: Makefile,v 1.4 2013/10/15 02:41:38 wen Exp $

DISTNAME=	Test-Warnings-0.012
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Warnings/
COMMENT=	Test for warnings and the lack of them
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-Module-Build-Tiny>=0.030:../../devel/p5-Module-Build-Tiny
PERL5_MODULE_TYPE=	Module::Build::Tiny

PERL5_PACKLIST=		auto/Test/Warnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
