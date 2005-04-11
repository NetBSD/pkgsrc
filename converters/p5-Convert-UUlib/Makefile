# $NetBSD: Makefile,v 1.14 2005/04/11 21:45:08 tv Exp $

DISTNAME=		Convert-UUlib-1.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5uul
PKGREVISION=		1
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module interface to the uulib library

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
