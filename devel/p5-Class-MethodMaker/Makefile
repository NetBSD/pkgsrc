# $NetBSD: Makefile,v 1.7 2005/04/11 21:45:30 tv Exp $
#

DISTNAME=		Class-MethodMaker-2.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-MethodMaker/
COMMENT=		Getter/setter OO method maker for class elements

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/MethodMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
