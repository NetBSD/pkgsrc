# $NetBSD: Makefile,v 1.7 2006/03/04 21:28:57 jlam Exp $
#

DISTNAME=	CDDB-1.12
PKGREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RC/RCAPUTO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=CDDB
COMMENT=	High-level interface to the Compact Disc Database

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CDDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
