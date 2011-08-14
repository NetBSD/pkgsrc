# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:33 obache Exp $
#

DISTNAME=	SUPER-1.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SUPER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SUPER/
COMMENT=	Perl 5 module to control superclass method dispatch
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Sub-Identify>=0.03:../../devel/p5-Sub-Identify
BUILD_DEPENDS+=	p5-Module-Build>=0.35:../../devel/p5-Module-Build

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/SUPER/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
