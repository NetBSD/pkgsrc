# $NetBSD: Makefile,v 1.7 2005/02/24 22:38:41 jlam Exp $

DISTNAME=	Class-Container-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ccr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Container/
COMMENT=	Glues object frameworks together transparently

DEPENDS+=	p5-Params-Validate>=0.23:../../devel/p5-Params-Validate
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Container/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
