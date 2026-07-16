# $NetBSD: Makefile,v 1.5 2026/07/16 19:03:29 wiz Exp $

DISTNAME=	Test-ExpectAndCheck-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
