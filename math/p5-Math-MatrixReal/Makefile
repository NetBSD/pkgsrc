# $NetBSD: Makefile,v 1.4 2002/10/28 00:05:42 seb Exp $

DISTNAME=	Math-MatrixReal-1.3a5
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mmr
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for performing operations on real matrices

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/MatrixReal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
