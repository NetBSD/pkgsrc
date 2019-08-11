# $NetBSD: Makefile,v 1.8 2019/08/11 13:18:49 wiz Exp $

DISTNAME=	Alien-Packages-0.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Alien-Packages
COMMENT=	Find information of installed packages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
DEPENDS+=	p5-Module-Pluggable>=4.8:../../devel/p5-Module-Pluggable

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Alien/Packages/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
