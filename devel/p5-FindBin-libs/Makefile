# $NetBSD: Makefile,v 1.20 2019/08/11 13:19:31 wiz Exp $

DISTNAME=		FindBin-libs-2.019002
PKGNAME=        	p5-${DISTNAME:S/.0/./:S/00/./}
PKGREVISION=        	2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FindBin/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/FindBin-libs
COMMENT=		Locate and a 'use lib' or export directories based on FindBin::Bin
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/FindBin/libs/.packlist

DEPENDS+=		p5-Module-FromPerlVer>=0.000005:../../devel/p5-Module-FromPerlVer
DEPENDS+=		p5-File-Copy-Recursive-Reduced>=0.006:../../sysutils/p5-File-Copy-Recursive-Reduced

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
