# $NetBSD: Makefile,v 1.5 2004/04/27 02:24:09 snj Exp $

DISTNAME=		Mac-Macbinary-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mmb
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for decoding Macbinary files

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mac/Macbinary/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
