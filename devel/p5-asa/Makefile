# $NetBSD: Makefile,v 1.17 2022/06/28 11:33:37 wiz Exp $

DISTNAME=	asa-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/asa
COMMENT=	Perl 5 module to overload isa functions
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/asa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
