# $NetBSD: Makefile,v 1.27 2014/10/09 14:06:13 wiz Exp $
#

DISTNAME=		Class-MethodMaker-2.18
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-MethodMaker/
COMMENT=		Getter/setter OO method maker for class elements
LICENSE=		${PERL5_LICENSE}

USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		auto/Class/MethodMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
