# $NetBSD: Makefile,v 1.13 2017/06/05 14:23:02 ryoon Exp $
#

DISTNAME=		FindBin-libs-2.15
PKGNAME=        	p5-${DISTNAME}
PKGREVISION=        	2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FindBin/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/FindBin-libs/
COMMENT=		Locate and a 'use lib' or export directories based on FindBin::Bin
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/FindBin/libs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
