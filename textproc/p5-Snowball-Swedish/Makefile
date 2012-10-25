# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:20 asau Exp $

DISTNAME=	Snowball-Swedish-1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASKSH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Snowball-Swedish/
COMMENT=	Porters stemming algorithm for Swedish
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/Se/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
