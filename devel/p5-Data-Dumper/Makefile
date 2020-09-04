# $NetBSD: Makefile,v 1.31 2020/09/04 11:19:08 wiz Exp $

DISTNAME=	Data-Dumper-2.173
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/X/XS/XSAWYERX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SMUELLER/Data-Dumper-2.167_02
COMMENT=	Stringified perl data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Simple>0:../../devel/p5-Test-Simple

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Data/Dumper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
