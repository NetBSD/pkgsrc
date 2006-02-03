# $NetBSD: Makefile,v 1.8 2006/02/03 00:58:25 wiz Exp $
#

DISTNAME=	CDDB_get-2.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FO/FONKIE/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://armin.emx.at/cddb/
COMMENT=	Perl interface to query for CDDB information

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CDDB_get/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
