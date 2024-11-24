# $NetBSD: Makefile,v 1.3 2024/11/24 09:36:14 wen Exp $

DISTNAME=	Test-ExpectAndCheck-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-ExpectAndCheck
COMMENT=	Expect/check-style unit testing with object methods
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/ExpectAndCheck/.packlist

DEPENDS+=	p5-Future>=0:../../devel/p5-Future

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
