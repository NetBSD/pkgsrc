# $NetBSD: Makefile,v 1.19 2022/06/28 11:36:24 wiz Exp $

DISTNAME=	Search-Indexer-0.79
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Search-Indexer
COMMENT=	Perl 5 module providing a full-text indexer
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Search/Indexer/.packlist

DEPENDS+=	p5-BerkeleyDB>=0.22:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Search-QueryParser>=0.91:../../databases/p5-Search-QueryParser

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
