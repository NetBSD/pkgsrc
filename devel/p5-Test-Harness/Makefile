# $NetBSD: Makefile,v 1.14 2003/07/21 16:43:42 martti Exp $

DISTNAME=		Test-Harness-2.28
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tha
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@NetBSD.org
COMMENT=		Perl5 module for testing

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Harness/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
