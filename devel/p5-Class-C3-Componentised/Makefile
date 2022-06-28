# $NetBSD: Makefile,v 1.22 2022/06/28 11:32:01 wiz Exp $

DISTNAME=	Class-C3-Componentised-1.001002
PKGNAME=	p5-${DISTNAME:S/00$//}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Class::C3::Componentised
COMMENT=	Load mix-ins or components to your C3-based class
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Class-C3>=0.20:../../devel/p5-Class-C3
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/C3/Componentised/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
