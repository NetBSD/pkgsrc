# $NetBSD: Makefile,v 1.9 2023/07/06 09:40:23 wiz Exp $

DISTNAME=	Tie-Simple-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HANENKAMP/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-Simple
COMMENT=	Variable ties made easier: much, much, much easier
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Tie/Simple/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
