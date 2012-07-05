# $NetBSD: Makefile,v 1.1 2012/07/05 13:55:41 sno Exp $

DISTNAME=	Sub-Exporter-GlobExporter-0.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Exporter-GlobExporter/
COMMENT=	Perl 5 module to export shared globs with Sub::Exporter collectors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/GlobExporter/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
