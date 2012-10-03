# $NetBSD: Makefile,v 1.17 2012/10/03 21:55:52 wiz Exp $
#

DISTNAME=	local-lib-1.008004
PKGNAME=	p5-${DISTNAME:S/008004/8.4/}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/local-lib/
COMMENT=	Create and use a local lib/ for perl modules with PERL5LIB
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/local/lib/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
