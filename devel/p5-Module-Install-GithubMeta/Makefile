# $NetBSD: Makefile,v 1.2 2015/06/12 10:49:27 wiz Exp $

DISTNAME=	Module-Install-GithubMeta-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bingos/Module-Install-GithubMeta/
COMMENT=	Module::Install extension to include GitHub meta info in META.yml
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=  # empty
PERL5_PACKLIST=	auto/Module/Install/GithubMeta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
