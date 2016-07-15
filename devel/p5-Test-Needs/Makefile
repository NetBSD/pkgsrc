# $NetBSD: Makefile,v 1.1 2016/07/15 10:06:58 wen Exp $

DISTNAME=	Test-Needs-0.002002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Needs/
COMMENT=	Skip tests when modules not available
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Test/Needs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
