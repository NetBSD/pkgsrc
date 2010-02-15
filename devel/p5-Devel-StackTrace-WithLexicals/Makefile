# $NetBSD: Makefile,v 1.2 2010/02/15 15:30:46 sno Exp $
#

DISTNAME=	Devel-StackTrace-WithLexicals-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-StackTrace-WithLexicals/
COMMENT=	Perl 5 module combining Devel::StackTrace and PadWalker
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/StackTrace/WithLexicals/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Devel-StackTrace>=1.2200:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-PadWalker-[0-9]*:../../devel/p5-PadWalker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
