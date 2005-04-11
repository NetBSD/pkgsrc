# $NetBSD: Makefile,v 1.3 2005/04/11 21:44:55 tv Exp $
#

DISTNAME=	CDDB-1.12
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RC/RCAPUTO/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=CDDB
COMMENT=	High-level interface to the Compact Disc Database

PKG_INSTALLATION_TYPES=	overwrite pkgviews


PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CDDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
