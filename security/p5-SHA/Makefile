# $NetBSD: Makefile,v 1.7 2003/07/17 22:53:06 grant Exp $
#

DISTNAME=		SHA-1.2
PKGNAME=		p5-SHA-1.2
SVR4_PKGNAME=		p5sha
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=SHA/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		perl5 interface to the SHA1 algorithm

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SHA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
