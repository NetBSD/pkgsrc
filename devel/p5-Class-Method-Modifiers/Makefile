# $NetBSD: Makefile,v 1.12 2013/01/26 19:44:43 rhaen Exp $

DISTNAME=	Class-Method-Modifiers-2.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Method-Modifiers/
COMMENT=	Perl module providing Moose-like method modifiers
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=		auto/Class/Method/Modifiers/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
