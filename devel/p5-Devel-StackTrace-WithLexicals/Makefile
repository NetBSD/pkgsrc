# $NetBSD: Makefile,v 1.13 2017/06/05 14:22:54 ryoon Exp $

DISTNAME=	Devel-StackTrace-WithLexicals-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-StackTrace-WithLexicals/
COMMENT=	Perl 5 module combining Devel::StackTrace and PadWalker
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-StackTrace>=1.2200:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-PadWalker>=1.9.2:../../devel/p5-PadWalker

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/StackTrace/WithLexicals/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
