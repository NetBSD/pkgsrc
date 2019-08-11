# $NetBSD: Makefile,v 1.2 2019/08/11 13:20:32 wiz Exp $

DISTNAME=	Test-LoadAllModules-0.022
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-LoadAllModules
COMMENT=	Run use_ok() on all modules in the search path
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils

PERL5_PACKLIST=	auto/Test/LoadAllModules/.packlist

PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
