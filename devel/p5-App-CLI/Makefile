# $NetBSD: Makefile,v 1.20 2017/11/08 16:26:24 wiz Exp $

DISTNAME=	App-CLI-0.49
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-CLI/
COMMENT=	Dispatcher module for command line interface programs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Class-Load-[0-9]*:../../devel/p5-Class-Load

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/App/CLI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
