# $NetBSD: Makefile,v 1.10 2005/07/13 18:01:33 jlam Exp $

DISTNAME=	Math-BigInteger-1.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mbi
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Arbitrary length integer extension module for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Math/BigInteger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
