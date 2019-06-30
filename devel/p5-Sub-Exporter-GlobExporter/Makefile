# $NetBSD: Makefile,v 1.14 2019/06/30 20:15:45 nia Exp $

DISTNAME=	Sub-Exporter-GlobExporter-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Exporter-GlobExporter
COMMENT=	Perl 5 module to export shared globs with Sub::Exporter collectors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

#BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/GlobExporter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
