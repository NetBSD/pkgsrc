# $NetBSD: Makefile,v 1.17 2022/06/28 11:33:48 wiz Exp $

DISTNAME=	Padre-Plugin-Nopaste-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-Nopaste
COMMENT=	Send code on a nopaste website from padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-App-Nopaste-[0-9]*:../../www/p5-App-Nopaste
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Module-Util-[0-9]*:../../devel/p5-Module-Util
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Padre>=0.30:../../editors/p5-Padre
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Padre/Plugin/Nopaste/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
