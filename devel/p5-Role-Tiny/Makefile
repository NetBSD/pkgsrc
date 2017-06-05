# $NetBSD: Makefile,v 1.23 2017/06/05 14:23:33 ryoon Exp $

DISTNAME=	Role-Tiny-2.000005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Role-Tiny/
COMMENT=	Roles. Like a nouvelle cuisine portion size slice of Moose
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-Moo<0.009014

BUILD_DEPENDS+=	p5-Test-Fatal>=0.003:../../devel/p5-Test-Fatal
#BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Role/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
