# $NetBSD: Makefile,v 1.24 2018/08/22 09:43:49 wiz Exp $

DISTNAME=	Data-Dumper-2.161
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SM/SMUELLER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~smueller/Data-Dumper/
COMMENT=	Stringified perl data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Simple>0:../../devel/p5-Test-Simple
DEPENDS+=	p5-ExtUtils-MakeMaker>0:../../devel/p5-ExtUtils-MakeMaker

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/Data/Dumper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
