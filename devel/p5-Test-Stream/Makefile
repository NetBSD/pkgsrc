# $NetBSD: Makefile,v 1.6 2018/08/22 09:44:50 wiz Exp $

DISTNAME=	Test-Stream-1.302027
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/E/EX/EXODIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/E/EX/EXODIST/
COMMENT=	Successor to Test::More and Test::Builder
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/Test/Stream/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
