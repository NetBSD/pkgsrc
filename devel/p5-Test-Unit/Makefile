# $NetBSD: Makefile,v 1.2 2002/10/13 22:00:30 seb Exp $

DISTNAME=	Test-Unit-0.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tun
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	cjs@netbsd.org
COMMENT=	Perl extension module for Unit Tests

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Unit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
