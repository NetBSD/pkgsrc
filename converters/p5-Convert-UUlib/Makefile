# $NetBSD: Makefile,v 1.13 2004/12/20 11:30:56 grant Exp $

DISTNAME=		Convert-UUlib-1.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5uul
PKGREVISION=		1
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module interface to the uulib library

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
