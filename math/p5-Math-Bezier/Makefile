# $NetBSD: Makefile,v 1.6 2004/12/20 11:31:05 grant Exp $

DISTNAME=	Math-Bezier-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for the solution of Bezier curves

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Bezier/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
