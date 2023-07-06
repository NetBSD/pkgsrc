# $NetBSD: Makefile,v 1.7 2023/07/06 09:40:13 wiz Exp $

DISTNAME=	Test-HexDifferences-1.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/ST/STEFFENW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-HexDifferences
COMMENT=	Test binary as hexadecimal string
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-Differences>=0.60:../../devel/p5-Test-Differences
DEPENDS+=	p5-Test-NoWarnings>=0:../../devel/p5-Test-NoWarnings
DEPENDS+=	p5-Text-Diff>=0:../../textproc/p5-Text-Diff

PERL5_PACKLIST=	auto/Test/HexDifferences/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
