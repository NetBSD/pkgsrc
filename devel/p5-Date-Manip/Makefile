# $NetBSD: Makefile,v 1.12 2003/07/25 12:02:23 jmmv Exp $
#

DISTNAME=     	DateManip-5.42a
PKGNAME=       	${DISTNAME:S/DateManip/p5-Date-Manip/}
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
