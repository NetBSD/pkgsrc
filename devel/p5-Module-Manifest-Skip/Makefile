# $NetBSD: Makefile,v 1.1 2015/04/28 12:07:23 mef Exp $

DISTNAME=	Module-Manifest-Skip-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ingy/Module-Manifest-Skip/
COMMENT=	Module::Manifest::Skip - MANIFEST.SKIP Manangement for Modules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Module/Manifest/Skip/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
