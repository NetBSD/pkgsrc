# $NetBSD: Makefile,v 1.25 2023/07/06 09:40:01 wiz Exp $

DISTNAME=		Sort-Versions-1.62
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Sort-Versions
COMMENT=		Perl5 module for sorting of revision-like numbers
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Sort/Versions/.packlist

CONFLICTS+=		p5-SortVersion-[0-9]*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
