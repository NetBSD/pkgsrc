# $NetBSD: Makefile,v 1.4 2013/05/31 12:40:42 wiz Exp $

DISTNAME=	Role-Identifiable-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Role-Identifiable/
COMMENT=	Perl 5 role with an ident attribute
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

BUILD_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Role/Identifiable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
