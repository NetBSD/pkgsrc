# $NetBSD: Makefile,v 1.2 2002/10/07 21:18:58 seb Exp $

DISTNAME=	Math-Bezier-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for the solution of Bezier curves

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Bezier/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
