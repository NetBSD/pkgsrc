# $NetBSD: Makefile,v 1.3 2003/07/17 21:32:47 grant Exp $
#

DISTNAME=	Set-Scalar-1.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ssc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?dist=Set-Scalar
COMMENT=	perl5 module for basic set operations

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Set/Scalar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
