# $NetBSD: Makefile,v 1.1.1.1 2012/03/08 09:58:30 sno Exp $

DISTNAME=	Module-Implementation-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Implementation/
COMMENT=	Loads one of several alternate underlying implementations for a Perl5 module
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

# ExtUtils::MakeMaker >= 6.30 is in core since 5.8.8
DEPENDS+=	p5-Module-Runtime>=0.12:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
# Test::More >= 0.88 is in core since 5.10.1
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Module/Implementation/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
