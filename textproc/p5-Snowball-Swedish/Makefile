# $NetBSD: Makefile,v 1.15 2020/09/02 13:02:10 mef Exp $

DISTNAME=	Snowball-Swedish-1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASKSH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Snowball-Swedish
COMMENT=	Porters stemming algorithm for Swedish
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/Se/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
