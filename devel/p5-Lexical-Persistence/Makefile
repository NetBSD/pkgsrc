# $NetBSD: Makefile,v 1.3 2008/11/17 03:04:01 he Exp $
#

DISTNAME=	Lexical-Persistence-0.98
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lexical/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lexical-Persistence/
COMMENT=	Perl 5 module providing persistent lexical variables

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Lexical/Persistence/.packlist

DEPENDS+=	p5-Devel-LexAlias>=0.04:../../devel/p5-Devel-LexAlias
DEPENDS+=	p5-PadWalker>=1.1:../../devel/p5-PadWalker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
