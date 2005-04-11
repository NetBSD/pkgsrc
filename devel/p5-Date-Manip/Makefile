# $NetBSD: Makefile,v 1.15 2005/04/11 21:45:31 tv Exp $
#

DISTNAME=     	DateManip-5.42a
PKGNAME=       	${DISTNAME:S/DateManip/p5-Date-Manip/}
SVR4_PKGNAME=	p5dma
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Perl5 module for date calculations

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Date/Manip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
