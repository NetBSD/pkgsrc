# $NetBSD: Makefile,v 1.5 2003/06/02 01:18:26 jschauma Exp $

DISTNAME=	Math-MatrixReal-1.3a5
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mmr
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module for performing operations on real matrices

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/MatrixReal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
