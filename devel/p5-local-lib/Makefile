# $NetBSD: Makefile,v 1.20 2013/07/13 09:37:37 wen Exp $
#

DISTNAME=	local-lib-1.008010
PKGNAME=	p5-${DISTNAME:S/008010/8.10/}
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
