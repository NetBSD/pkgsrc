# $NetBSD: Makefile,v 1.1.1.1 2004/10/18 03:44:05 ben Exp $
#

DISTNAME=	CDDB_get-2.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FO/FONKIE/}

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://armin.emx.at/cddb/
COMMENT=	Perl interface to query for cddb-information

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CDDB_get/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
