# $NetBSD: Makefile,v 1.18 2017/06/05 14:23:35 ryoon Exp $

DISTNAME=		Sort-Versions-1.62
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sort-Versions/
COMMENT=		Perl5 module for sorting of revision-like numbers
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Sort/Versions/.packlist

CONFLICTS+=		p5-SortVersion-[0-9]*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
