# $NetBSD: Makefile,v 1.6 2012/09/13 15:04:59 sno Exp $
#

DISTNAME=		Hash-MultiValue-0.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Hash-MultiValue/
COMMENT=		Perl5 module to store multiple values per key
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Hash/MultiValue/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
