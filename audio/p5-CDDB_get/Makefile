# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:04 jlam Exp $
#

DISTNAME=	CDDB_get-2.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FO/FONKIE/}

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://armin.emx.at/cddb/
COMMENT=	Perl interface to query for CDDB information

PKG_INSTALLATION_TYPES=	overwrite pkgviews


PERL5_PACKLIST=		auto/CDDB_get/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
