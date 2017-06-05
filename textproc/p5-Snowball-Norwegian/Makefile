# $NetBSD: Makefile,v 1.10 2017/06/05 14:24:45 ryoon Exp $

DISTNAME=	Snowball-Norwegian-1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASKSH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Snowball-Norwegian/
COMMENT=	Porters stemming algorithm for Norwegian
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/No/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
