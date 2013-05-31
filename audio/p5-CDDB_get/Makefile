# $NetBSD: Makefile,v 1.19 2013/05/31 12:39:37 wiz Exp $

DISTNAME=	CDDB_get-2.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FO/FONKIE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://armin.emx.at/cddb/
COMMENT=	Perl interface to query for CDDB information
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CDDB_get/.packlist

USE_LANGUAGES=		# empty
REPLACE_PERL+=		cddb.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
