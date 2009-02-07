# $NetBSD: Makefile,v 1.1.1.1 2009/02/07 15:12:11 seb Exp $
#

DISTNAME=	Devel-StackTrace-WithLexicals-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-StackTrace-WithLexicals/
COMMENT=	Perl 5 module combining Devel::StackTrace and PadWalker

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Devel/StackTrace/WithLexicals/.packlist

DEPENDS+=	p5-Devel-StackTrace>=1.1902:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-PadWalker-[0-9]*:../../devel/p5-PadWalker

# For test
BUILD_DEPENDS+=	p5-Exception-Class>=1.09:../../devel/p5-Exception-Class

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
