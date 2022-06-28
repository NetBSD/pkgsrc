# $NetBSD: Makefile,v 1.11 2022/06/28 11:32:11 wiz Exp $

DISTNAME=	Data-Record-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Record
COMMENT=	Perl5 module for "split" on steroids
LICENSE=	${PERL5_LICENSE}

# actually, TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Record/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
