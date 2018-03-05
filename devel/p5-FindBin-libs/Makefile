# $NetBSD: Makefile,v 1.15 2018/03/05 13:09:56 wiz Exp $

DISTNAME=		FindBin-libs-2.16
PKGNAME=        	p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FindBin/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/FindBin-libs/
COMMENT=		Locate and a 'use lib' or export directories based on FindBin::Bin
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/FindBin/libs/.packlist

DEPENDS+=		p5-Module-FromPerlVer>=0.000005:../../devel/p5-Module-FromPerlVer

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
