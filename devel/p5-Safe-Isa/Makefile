# $NetBSD: Makefile,v 1.18 2023/07/06 09:39:58 wiz Exp $

DISTNAME=	Safe-Isa-1.000010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Safe-Isa
COMMENT=	Call isa, can, does and DOES safely on things that may not be objects
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Safe/Isa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
