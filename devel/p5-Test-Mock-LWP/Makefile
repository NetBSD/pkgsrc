# $NetBSD: Makefile,v 1.12 2016/06/08 19:23:39 wiz Exp $
#

DISTNAME=	Test-Mock-LWP-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Mock-LWP/
COMMENT=	Perl 5 package providing easy mocking of LWP packages
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Mock/LWP/.packlist

DEPENDS+=	p5-Test-MockObject>=1.08:../../devel/p5-Test-MockObject

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
