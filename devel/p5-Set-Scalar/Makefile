# $NetBSD: Makefile,v 1.1.1.1 2003/05/17 18:56:25 dmcmahill Exp $
#

DISTNAME=	Set-Scalar-1.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ssc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/search?dist=Set-Scalar
COMMENT=	perl5 module for basic set operations

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Set/Scalar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
