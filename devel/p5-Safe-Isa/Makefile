# $NetBSD: Makefile,v 1.12 2018/08/22 09:44:36 wiz Exp $

DISTNAME=	Safe-Isa-1.000010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Safe-Isa/
COMMENT=	Call isa, can, does and DOES safely on things that may not be objects
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Safe/Isa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
