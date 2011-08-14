# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:41 obache Exp $
#

DISTNAME=		Test-Kwalitee-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Kwalitee/
COMMENT=		Perl5 module to test the Kwalitee of a distribution

DEPENDS+=  p5-Module-CPANTS-Analyse>=0.82:../../devel/p5-Module-CPANTS-Analyse

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Kwalitee/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
