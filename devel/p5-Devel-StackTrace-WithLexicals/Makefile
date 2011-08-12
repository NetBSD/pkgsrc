# $NetBSD: Makefile,v 1.5 2011/08/12 11:50:51 adam Exp $

DISTNAME=	Devel-StackTrace-WithLexicals-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-StackTrace-WithLexicals/
COMMENT=	Perl 5 module combining Devel::StackTrace and PadWalker
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Devel-StackTrace>=1.2200:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-PadWalker>=1.9.2:../../devel/p5-PadWalker

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/StackTrace/WithLexicals/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
