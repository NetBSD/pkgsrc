# $NetBSD: Makefile,v 1.2 2004/12/20 11:30:59 grant Exp $
#

DISTNAME=     	Date-Business-1.2
PKGNAME=       	${DISTNAME:S/Date-Business/p5-Date-Business/}
SVR4_PKGNAME=	p5dbu
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Perl5 module for fast calendar and business date calculations

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Date/Business/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
