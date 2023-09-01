# $NetBSD: Makefile,v 1.20 2023/09/01 09:49:28 nia Exp $

DISTNAME=	Text-Hunspell-2.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Hunspell
COMMENT=	Perl module to interface with GNU Hunspell
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Alien-Hunspell-[0-9]*:../../textproc/p5-Alien-Hunspell

USE_LANGUAGES=		c c++

# Mostly needed due to hunspell headers making c++98 default unacceptable.
FORCE_CXX_STD=		c++11
USE_CXX_FEATURES+=	c++11

PERL5_PACKLIST=	auto/Text/Hunspell/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
