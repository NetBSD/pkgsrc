# $NetBSD: Makefile,v 1.12 2022/06/28 11:32:46 wiz Exp $

DISTNAME=	Module-Install-GithubMeta-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Install-GithubMeta
COMMENT=	Module::Install extension to include GitHub meta info in META.yml
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Install/GithubMeta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
