# $NetBSD: Makefile,v 1.1.1.1 2002/12/13 17:27:26 cjep Exp $

DISTNAME=		Mac-Macbinary-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mmb
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for decoding Macbinary files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mac/Macbinary/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
