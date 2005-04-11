# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:35 tv Exp $

DISTNAME=	Storable-2.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sto
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Storable/
COMMENT=	Perl extension module for persistent data storage

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
