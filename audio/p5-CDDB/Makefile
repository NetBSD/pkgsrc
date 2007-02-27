# $NetBSD: Makefile,v 1.9 2007/02/27 08:54:46 wiz Exp $
#

DISTNAME=	CDDB-1.17
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RC/RCAPUTO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CDDB/
COMMENT=	High-level interface to the Compact Disc Database

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CDDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
