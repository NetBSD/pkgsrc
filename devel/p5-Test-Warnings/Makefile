# $NetBSD: Makefile,v 1.3 2013/09/15 13:12:49 wiz Exp $

DISTNAME=	Test-Warnings-0.009
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Warnings/
COMMENT=	Test for warnings and the lack of them
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-Module-Build-Tiny>=0.027:../../devel/p5-Module-Build-Tiny
PERL5_MODULE_TYPE=	Module::Build::Tiny

PERL5_PACKLIST=		auto/Test/Warnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
