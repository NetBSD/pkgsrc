# $NetBSD: Makefile,v 1.8 2012/07/06 14:10:22 sno Exp $
#

DISTNAME=	SUPER-1.20120705
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SUPER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SUPER/
COMMENT=	Perl 5 module to control superclass method dispatch
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Sub-Identify>=0.03:../../devel/p5-Sub-Identify

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/SUPER/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
