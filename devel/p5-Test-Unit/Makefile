# $NetBSD: Makefile,v 1.4 2004/04/25 03:14:04 minskim Exp $

DISTNAME=	Test-Unit-0.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tun
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	cjs@NetBSD.org
COMMENT=	Perl extension module for Unit Tests

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Unit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
