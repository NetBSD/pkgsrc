# $NetBSD: Makefile,v 1.14 2009/07/07 19:24:34 sno Exp $
#

DISTNAME=		Array-Compare-1.18
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
#MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAVECROSS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Array-Compare/
COMMENT=		Perl extension for comparing arrays
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Array/Compare/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
