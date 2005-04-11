# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:34 tv Exp $
#

DISTNAME=	Set-IntSpan-1.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sis
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-IntSpan/
COMMENT=	Perl5 module for managing sets of integers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Set/IntSpan/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
