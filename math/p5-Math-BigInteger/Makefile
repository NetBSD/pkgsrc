# $NetBSD: Makefile,v 1.7 2004/02/17 04:22:55 minskim Exp $

DISTNAME=	Math-BigInteger-1.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mbi
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Arbitrary length integer extension module for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/BigInteger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
