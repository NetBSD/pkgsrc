# $NetBSD: Makefile,v 1.19 2019/06/30 20:15:35 nia Exp $

DISTNAME=	Path-Dispatcher-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SARTAK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Path-Dispatcher
COMMENT=	Perl 5 module providing flexible and extensible dispatch
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

# For test target
BUILD_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/Path/Dispatcher/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
