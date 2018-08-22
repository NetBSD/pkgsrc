# $NetBSD: Makefile,v 1.17 2018/08/22 09:45:56 wiz Exp $
#

DISTNAME=	Data-Stream-Bulk-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Stream-Bulk/
COMMENT=	N at a time iteration API for data transfers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean
DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple
# For tests:
BUILD_DEPENDS+=	p5-Test-TempDir>=0:../../devel/p5-Test-TempDir
BUILD_DEPENDS+=	p5-DBD-Mock>=1.37:../../databases/p5-DBD-Mock

PERL5_PACKLIST=	auto/Data/Stream/Bulk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
