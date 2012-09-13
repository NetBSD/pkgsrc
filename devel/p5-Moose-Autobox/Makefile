# $NetBSD: Makefile,v 1.8 2012/09/13 15:51:53 sno Exp $
#

DISTNAME=	Moose-Autobox-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Moose-Autobox/
COMMENT=	Perl 5 module providing autoboxed wrappers for native datatypes
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Moose/Autobox/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-autobox>=2.23:../../devel/p5-autobox
DEPENDS+=	p5-Moose>=0.42:../../devel/p5-Moose
DEPENDS+=	p5-Syntax-Keyword-Junction-[0-9]*:../../devel/p5-Syntax-Keyword-Junction

BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
