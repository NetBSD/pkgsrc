# $NetBSD: Makefile,v 1.8 2002/10/13 22:22:54 seb Exp $
#

DISTNAME=     	DateManip-5.39
PKGNAME=       	p5-Date-Manip-5.39
SVR4_PKGNAME=	p5dma
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	perl5 module for date calculations

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Date/Manip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
