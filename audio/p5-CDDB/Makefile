# $NetBSD: Makefile,v 1.16 2012/10/02 23:48:03 asau Exp $

DISTNAME=	CDDB-1.220
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CDDB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CDDB/
COMMENT=	High-level interface to the Compact Disc Database
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	CDDB-[0-9]*
SUPERSEDES=	CDDB<=1.17nb1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CDDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
