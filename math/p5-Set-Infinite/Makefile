# $NetBSD: Makefile,v 1.1.1.1 2005/01/25 14:33:00 cube Exp $

DISTNAME=	Set-Infinite-0.61
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Infinite/
COMMENT=	Perl module for sets of integers and objects

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Set/Infinite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
