# $NetBSD: Makefile,v 1.25 2020/08/31 18:07:27 wiz Exp $

DISTNAME=	App-CLI-0.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/App-CLI
COMMENT=	Dispatcher module for command line interface programs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Class-Load-[0-9]*:../../devel/p5-Class-Load

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/App/CLI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
