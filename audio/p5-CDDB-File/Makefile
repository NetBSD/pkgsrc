# $NetBSD: Makefile,v 1.10 2014/05/29 23:35:15 wiz Exp $

DISTNAME=	CDDB-File-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CDDB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CDDB-File/
COMMENT=	Parses a CDDB/freedb data file
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/CDDB/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
