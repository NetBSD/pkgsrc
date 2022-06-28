# $NetBSD: Makefile,v 1.18 2022/06/28 11:36:19 wiz Exp $

DISTNAME=	Lingua-Stem-Ru-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-Stem-Ru
COMMENT=	Porter's stemming algorithm for Russian (KOI8-R only)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Lingua/Stem/Ru/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
