# $NetBSD: Makefile,v 1.13 2019/06/30 20:16:07 nia Exp $

DISTNAME=	Padre-Plugin-SpellCheck-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-SpellCheck
COMMENT=	Check spelling in Padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-XSAccessor-[0-9]*:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-Module-Util-[0-9]*:../../devel/p5-Module-Util
DEPENDS+=	p5-Padre>=0.26:../../editors/p5-Padre
DEPENDS+=	p5-Text-Aspell-[0-9]*:../../textproc/p5-Text-Aspell
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Padre/Plugin/SpellCheck/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
