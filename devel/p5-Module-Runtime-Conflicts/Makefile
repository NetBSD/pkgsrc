# $NetBSD: Makefile,v 1.11 2021/05/24 19:51:05 wiz Exp $

DISTNAME=		Module-Runtime-Conflicts-0.003
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Module-Runtime-Conflicts
COMMENT=		Provide information on conflicts for Module::Runtime
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Dist-CheckConflicts-[0-9]*:../../devel/p5-Dist-CheckConflicts
DEPENDS+=		p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

#PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Runtime/Conflicts/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
