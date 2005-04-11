# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:29 tv Exp $

DISTNAME=	Attribute-Handlers-0.78
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ah
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Attribute-Handlers/
COMMENT=	Simpler definition of attribute handlers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Attribute/Handlers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
