# $NetBSD: Makefile,v 1.19 2017/06/05 14:22:43 ryoon Exp $

DISTNAME=	Class-Method-Modifiers-2.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Method-Modifiers/
COMMENT=	Perl module providing Moose-like method modifiers
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Class/Method/Modifiers/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
