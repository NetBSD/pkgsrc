# $NetBSD: Makefile,v 1.10 2003/07/17 21:32:16 grant Exp $
#

VERS=		5.40
DISTNAME=     	DateManip-${VERS}
PKGNAME=       	p5-Date-Manip-${VERS}
SVR4_PKGNAME=	p5dma
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	perl5 module for date calculations

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Date/Manip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
