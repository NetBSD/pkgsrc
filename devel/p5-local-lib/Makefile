# $NetBSD: Makefile,v 1.19 2013/05/31 12:40:55 wiz Exp $
#

DISTNAME=	local-lib-1.008004
PKGNAME=	p5-${DISTNAME:S/008004/8.4/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/local-lib/
COMMENT=	Create and use a local lib/ for perl modules with PERL5LIB
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/local/lib/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
