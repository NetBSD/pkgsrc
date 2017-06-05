# $NetBSD: Makefile,v 1.15 2017/06/05 14:23:10 ryoon Exp $
#

DISTNAME=	Lexical-Persistence-1.023
PKGNAME=	p5-${DISTNAME:S/020/02/}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lexical/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lexical-Persistence/
COMMENT=	Perl 5 module providing persistent lexical variables
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Lexical/Persistence/.packlist

DEPENDS+=	p5-Devel-LexAlias>=0.05:../../devel/p5-Devel-LexAlias
DEPENDS+=	p5-PadWalker>=1.9.6:../../devel/p5-PadWalker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
