# $NetBSD: Makefile,v 1.2 2016/06/08 19:22:38 wiz Exp $

DISTNAME=	Cache-LRU-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Cache-LRU/
COMMENT=	Simple, fast implementation of an in-memory LRU cache
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires

USE_LANGUAGES=	# none

PERL5_PACKLIST=	auto/Cache/LRU/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
