# $NetBSD: Makefile,v 1.11 2003/07/21 16:43:36 martti Exp $
#

VERS=		5.40
DISTNAME=     	DateManip-${VERS}
PKGNAME=       	p5-Date-Manip-${VERS}
SVR4_PKGNAME=	p5dma
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Perl5 module for date calculations

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Date/Manip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
