# $NetBSD: Makefile,v 1.4 2004/04/25 04:02:54 minskim Exp $

DISTNAME=	Error-0.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5err
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Error/}

MAINTAINER=	cjs@NetBSD.org
COMMENT=	Perl extension module for try/throw/catch exception handling

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Error/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
