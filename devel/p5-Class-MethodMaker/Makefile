# $NetBSD: Makefile,v 1.36 2019/06/30 20:14:41 nia Exp $
#

DISTNAME=		Class-MethodMaker-2.24
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Class-MethodMaker
COMMENT=		Getter/setter OO method maker for class elements
LICENSE=		${PERL5_LICENSE}

USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		auto/Class/MethodMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
