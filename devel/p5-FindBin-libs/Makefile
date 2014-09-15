# $NetBSD: Makefile,v 1.8 2014/09/15 21:54:19 schmonz Exp $
#

DISTNAME=		FindBin-libs-2.11
PKGNAME=        	p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FindBin/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/FindBin-libs/
COMMENT=		Locate and a 'use lib' or export directories based on FindBin::Bin
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/FindBin/libs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
