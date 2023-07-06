# $NetBSD: Makefile,v 1.14 2023/07/06 09:39:16 wiz Exp $

DISTNAME=	Git-Repository-Plugin-AUTOLOAD-1.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Git-Repository-Plugin-AUTOLOAD
COMMENT=	Git subcommands as Git::Repository methods
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Git-Repository>=1.309:../../devel/p5-Git-Repository
# for make test
TOOL_DEPENDS+=	p5-Test-Requires-Git-[0-9]*:../../devel/p5-Test-Requires-Git
TOOL_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

PERL5_PACKLIST=	auto/Git/Repository/Plugin/AUTOLOAD/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
