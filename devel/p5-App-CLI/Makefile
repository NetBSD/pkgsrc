# $NetBSD: Makefile,v 1.29 2023/07/06 09:38:35 wiz Exp $

DISTNAME=	App-CLI-0.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/App-CLI
COMMENT=	Dispatcher module for command line interface programs
LICENSE=	artistic

DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Class-Load-[0-9]*:../../devel/p5-Class-Load

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/App/CLI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
