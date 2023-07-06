# $NetBSD: Makefile,v 1.22 2023/07/06 09:40:32 wiz Exp $

DISTNAME=	Padre-Plugin-Git-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-Git
COMMENT=	Simple Git interface for Padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.03:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Padre>=0.67:../../editors/p5-Padre
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
# TEST_DEPENDS
TOOL_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TOOL_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TOOL_DEPENDS+=	p5-CPAN-Changes-[0-9]*:../../devel/p5-CPAN-Changes
# Pithub?

PERL5_PACKLIST=		auto/Padre/Plugin/Git/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
