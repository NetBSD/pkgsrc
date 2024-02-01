# $NetBSD: Makefile,v 1.1 2024/02/01 04:19:28 schmonz Exp $

DISTNAME=		ClamAV-Client-0.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMEHNLE/clamav-client/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/ClamAV::Client
COMMENT=		Client class for the ClamAV clamd virus scanner
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Error>=0:../../devel/p5-Error

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/ClamAV/Client/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
