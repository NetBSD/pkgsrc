# $NetBSD: Makefile,v 1.13.4.1 2005/05/02 16:22:43 salo Exp $

DISTNAME=		Convert-UUlib-1.051
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5uul
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-UUlib/
COMMENT=		Perl5 module interface to the uulib library

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
