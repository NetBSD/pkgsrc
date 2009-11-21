# $NetBSD: Makefile,v 1.1.1.1 2009/11/21 13:55:04 sno Exp $
#

DISTNAME=	MooseX-Role-WithOverloading-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Role-WithOverloading/
COMMENT=	Moose extension for roles which support overloading
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Moose>=0.90:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-aliased-[0-9]*:../../devel/p5-aliased
DEPENDS+=	p5-namespace-autoclean>=0.09:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/MooseX/Role/WithOverloading/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
