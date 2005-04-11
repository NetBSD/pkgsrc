# $NetBSD: Makefile,v 1.4 2005/04/11 21:44:56 tv Exp $
#

DISTNAME=	CDDB_get-2.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FO/FONKIE/}

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://armin.emx.at/cddb/
COMMENT=	Perl interface to query for CDDB information

PKG_INSTALLATION_TYPES=	overwrite pkgviews


PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CDDB_get/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
