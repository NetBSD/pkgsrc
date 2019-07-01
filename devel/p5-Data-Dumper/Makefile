# $NetBSD: Makefile,v 1.27 2019/07/01 21:35:35 nia Exp $

DISTNAME=	Data-Dumper-2.173
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/X/XS/XSAWYERX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SMUELLER/Data-Dumper-2.167_02
COMMENT=	Stringified perl data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Simple>0:../../devel/p5-Test-Simple
DEPENDS+=	p5-ExtUtils-MakeMaker>0:../../devel/p5-ExtUtils-MakeMaker

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/Data/Dumper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
