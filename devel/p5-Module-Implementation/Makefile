# $NetBSD: Makefile,v 1.12 2018/08/22 09:44:17 wiz Exp $

DISTNAME=	Module-Implementation-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Implementation/
COMMENT=	Loads one of several alternate underlying implementations
LICENSE=	artistic-2.0

# ExtUtils::MakeMaker >= 6.30 is in core since 5.8.8
DEPENDS+=	p5-Module-Runtime>=0.12:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
# Test::More >= 0.88 is in core since 5.10.1
BUILD_DEPENDS+=	p5-Test-Fatal>=0.006:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Module/Implementation/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
