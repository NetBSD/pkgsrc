# $NetBSD: Makefile,v 1.5 2003/06/02 01:17:13 jschauma Exp $
#

DISTNAME=		Crypt-DES-2.03
PKGNAME=		p5-Crypt-DES-2.03
SVR4_PKGNAME=		p5des
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		XS-based DES implementation for Perl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/DES/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
