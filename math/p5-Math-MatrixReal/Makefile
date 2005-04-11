# $NetBSD: Makefile,v 1.9 2005/04/11 21:46:30 tv Exp $

DISTNAME=	Math-MatrixReal-1.3a5
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mmr
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for performing operations on real matrices

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/MatrixReal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
