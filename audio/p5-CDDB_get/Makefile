# $NetBSD: Makefile,v 1.10 2006/06/18 11:11:11 rillig Exp $
#

DISTNAME=	CDDB_get-2.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FO/FONKIE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://armin.emx.at/cddb/
COMMENT=	Perl interface to query for CDDB information

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CDDB_get/.packlist

REPLACE_PERL+=		cddb.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
