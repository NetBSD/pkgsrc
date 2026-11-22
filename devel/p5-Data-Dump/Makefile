# $NetBSD: Makefile,v 1.31 2026/11/22 08:30:35 wiz Exp $

DISTNAME=	Data-Dump-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GA/GARU/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Dump
COMMENT=	Pretty printing of data structures
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Dump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
