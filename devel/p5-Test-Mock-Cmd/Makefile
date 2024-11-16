# $NetBSD: Makefile,v 1.3 2024/11/16 12:05:19 wiz Exp $

DISTNAME=		Test-Mock-Cmd-0.7
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DM/DMUEY/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Test::Mock::Cmd
COMMENT=		Mock system(), exec(), and qx() for testing
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Test-Carp-[0-9]*:../../devel/p5-Test-Carp

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Test/Mock/Cmd/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
