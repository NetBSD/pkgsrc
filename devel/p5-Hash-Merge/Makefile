# $NetBSD: Makefile,v 1.1.1.1 2008/08/23 18:24:01 seb Exp $
#

DISTNAME=	Hash-Merge-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hash-Merge/
COMMENT=	Perl 5 module to merges arbitrarily deep hashes

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Hash/Merge/.packlist

DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
