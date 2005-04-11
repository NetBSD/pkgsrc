# $NetBSD: Makefile,v 1.7 2005/04/11 21:46:39 tv Exp $

DISTNAME=		Mac-Macbinary-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mmb
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for decoding Macbinary files

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mac/Macbinary/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
