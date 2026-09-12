# $NetBSD: Makefile,v 1.32 2026/09/12 20:46:14 wiz Exp $

DISTNAME=	Sub-Exporter-0.992
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Exporter
COMMENT=	Sophisticated exporter for custom-built routines
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-OptList>=0.100:../../devel/p5-Data-OptList
DEPENDS+=	p5-Params-SomeUtil>=0:../../devel/p5-Params-SomeUtil
DEPENDS+=	p5-Sub-Install>=0.920:../../devel/p5-Sub-Install

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Sub/Exporter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
