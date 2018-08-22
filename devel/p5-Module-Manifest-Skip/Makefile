# $NetBSD: Makefile,v 1.7 2018/08/22 09:44:18 wiz Exp $

DISTNAME=	Module-Manifest-Skip-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ingy/Module-Manifest-Skip/
COMMENT=	Module::Manifest::Skip - MANIFEST.SKIP Manangement for Modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-ShareDir-Install>=0.06:../../devel/p5-File-ShareDir-Install
# for make test
BUILD_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo

PERL5_PACKLIST=	auto/Module/Manifest/Skip/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
