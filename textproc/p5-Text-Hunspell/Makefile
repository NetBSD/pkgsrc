# $NetBSD: Makefile,v 1.12 2019/08/11 13:23:44 wiz Exp $

DISTNAME=	Text-Hunspell-2.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Hunspell
COMMENT=	Perl module to interface with GNU Hunspell
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Alien-Hunspell-[0-9]*:../../textproc/p5-Alien-Hunspell

USE_LANGUAGES=          c c++

PERL5_PACKLIST=	auto/Text/Hunspell/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
