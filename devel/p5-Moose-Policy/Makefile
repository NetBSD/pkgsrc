# $NetBSD: Makefile,v 1.11 2016/06/08 19:23:14 wiz Exp $
#

DISTNAME=	Moose-Policy-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FL/FLORA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Moose-Policy/
COMMENT=	Moose-mounted police
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Moose/Policy/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Moose>=0.84:../../devel/p5-Moose
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
