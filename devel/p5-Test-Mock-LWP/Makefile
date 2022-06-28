# $NetBSD: Makefile,v 1.20 2022/06/28 11:33:26 wiz Exp $
#

DISTNAME=	Test-Mock-LWP-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Mock-LWP
COMMENT=	Perl 5 package providing easy mocking of LWP packages
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Test/Mock/LWP/.packlist

DEPENDS+=	p5-Test-MockObject>=1.08:../../devel/p5-Test-MockObject

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
