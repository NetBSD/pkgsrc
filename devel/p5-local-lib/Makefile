# $NetBSD: Makefile,v 1.8 2010/03/15 19:00:15 sno Exp $
#

DISTNAME=	local-lib-1.005001
PKGNAME=	p5-${DISTNAME:S/005001/5.1/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AP/APEIRON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/local-lib/
COMMENT=	Create and use a local lib/ for perl modules with PERL5LIB
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/local/lib/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
