# $NetBSD: Makefile,v 1.1 2015/02/07 08:47:27 wiz Exp $

DISTNAME=	Git-Repository-Plugin-AUTOLOAD-1.001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Git-Repository-Plugin-AUTOLOAD/
COMMENT=	Git subcommands as Git::Repository methods
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Git-Repository>=1.309:../../devel/p5-Git-Repository

PERL5_PACKLIST=	auto/Git/Repository/Plugin/AUTOLOAD/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
