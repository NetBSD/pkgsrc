# $NetBSD: Makefile,v 1.10 2016/06/08 19:23:31 wiz Exp $

DISTNAME=	Sub-Exporter-GlobExporter-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Exporter-GlobExporter/
COMMENT=	Perl 5 module to export shared globs with Sub::Exporter collectors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

#BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/GlobExporter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
