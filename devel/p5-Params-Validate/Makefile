# $NetBSD: Makefile,v 1.17 2005/04/11 21:45:34 tv Exp $

DISTNAME=	Params-Validate-0.76
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pva
PKGREVISION=	# empty
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Params-Validate/
COMMENT=	Validate method/function parameters

DEPENDS+=	p5-Attribute-Handlers>=0.76:../../devel/p5-Attribute-Handlers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Params/Validate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
