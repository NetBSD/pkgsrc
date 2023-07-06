# $NetBSD: Makefile,v 1.14 2023/07/06 09:40:19 wiz Exp $

DISTNAME=	Test-Stream-1.302027
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::Stream
COMMENT=	Successor to Test::More and Test::Builder
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Test/Stream/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
