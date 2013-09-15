# $NetBSD: Makefile,v 1.2 2013/09/15 00:52:54 wen Exp $

DISTNAME=	Test-Warnings-0.008
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Warnings/
COMMENT=	Test for warnings and the lack of them
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build::Tiny

PERL5_PACKLIST=		auto/Test/Warnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
