# $NetBSD: Makefile,v 1.19 2018/08/22 09:45:39 wiz Exp $
#

DISTNAME=	Math-Random-0.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/Math-Random/
COMMENT=	Random number generators

PERL5_PACKLIST=	auto/Math/Random/.packlist

REPLACE_PERL=	example.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
