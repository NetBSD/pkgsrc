# $NetBSD: Makefile,v 1.5 2003/06/02 01:18:27 jschauma Exp $

DISTNAME=	Math-BigInteger-1.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mbi
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Arbitrary length integer extension module for Perl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/BigInteger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
