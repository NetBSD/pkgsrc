# $NetBSD: Makefile,v 1.28 2026/07/16 19:03:26 wiz Exp $
#

DISTNAME=	Test-Base-0.89
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Base
COMMENT=	Perl 5 module providing a data driven testing framework
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Base/.packlist

DEPENDS+=	p5-Spiffy>=0.30:../../devel/p5-Spiffy
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
