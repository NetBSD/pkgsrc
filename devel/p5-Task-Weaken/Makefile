# $NetBSD: Makefile,v 1.12 2013/05/31 12:40:45 wiz Exp $
#

DISTNAME=	Task-Weaken-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Task/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist//Task-Weaken/
COMMENT=	Perl 5 module to ensure that a platform has weaken support
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=	auto/Task/Weaken/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
