# $NetBSD: Makefile,v 1.1.1.1 2009/08/22 12:01:37 seb Exp $
#

DISTNAME=	lib-abs-0.90
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/lib-abs/
COMMENT=	Perl 5 module to add in @INC absolute paths from relative ones
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/lib/abs/.packlist
# This module uses Module::Install but only depends on modern
# core modules so there is no need to bring in the build dependencies
# of devel/p5-Module-Install
#PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
