# $NetBSD: Makefile,v 1.4 2005/02/19 11:21:37 wiz Exp $
#

DISTNAME=		Class-MethodMaker-2.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://search.cpan.org/dist/Class-MethodMaker/
COMMENT=		Getter/setter OO method maker for class elements

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/MethodMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
