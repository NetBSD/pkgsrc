# $NetBSD: Makefile,v 1.4 2016/06/08 19:23:12 wiz Exp $

DISTNAME=	Module-Manifest-Skip-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ingy/Module-Manifest-Skip/
COMMENT=	Module::Manifest::Skip - MANIFEST.SKIP Manangement for Modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-ShareDir-Install>=0.06:../../devel/p5-File-ShareDir-Install

PERL5_PACKLIST=	auto/Module/Manifest/Skip/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
