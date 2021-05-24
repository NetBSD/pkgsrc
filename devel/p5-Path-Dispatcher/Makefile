# $NetBSD: Makefile,v 1.23 2021/05/24 19:51:23 wiz Exp $

DISTNAME=	Path-Dispatcher-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Path-Dispatcher
COMMENT=	Perl 5 module providing flexible and extensible dispatch
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-MooX-TypeTiny-[0-9]*:../../devel/p5-MooX-TypeTiny
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Path/Dispatcher/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
