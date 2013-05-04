# $NetBSD: Makefile,v 1.9 2013/05/04 11:19:10 hiramatsu Exp $
#

DISTNAME=		Hash-MultiValue-0.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Hash-MultiValue/
COMMENT=		Perl5 module to store multiple values per key
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Hash/MultiValue/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
