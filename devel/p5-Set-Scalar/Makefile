# $NetBSD: Makefile,v 1.5 2004/04/25 03:21:23 minskim Exp $
#

DISTNAME=	Set-Scalar-1.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ssc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?dist=Set-Scalar
COMMENT=	Perl5 module for basic set operations

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Set/Scalar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
