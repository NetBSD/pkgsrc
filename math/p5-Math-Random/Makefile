# $NetBSD: Makefile,v 1.21 2019/08/11 13:21:48 wiz Exp $
#

DISTNAME=	Math-Random-0.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	https://metacpan.org/release/Math-Random
COMMENT=	Random number generators

PERL5_PACKLIST=	auto/Math/Random/.packlist

REPLACE_PERL=	example.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
