# $NetBSD: Makefile,v 1.9 2013/10/02 07:32:27 wen Exp $

DISTNAME=	Role-Tiny-1.003002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Role-Tiny/
COMMENT=	Roles. Like a nouvelle cuisine portion size slice of Moose
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-Moo<0.009014

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=	p5-Test-Fatal>=0.003:../../devel/p5-Moose
BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Role/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
