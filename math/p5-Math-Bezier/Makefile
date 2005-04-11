# $NetBSD: Makefile,v 1.7 2005/04/11 21:46:30 tv Exp $

DISTNAME=	Math-Bezier-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for the solution of Bezier curves

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Bezier/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
