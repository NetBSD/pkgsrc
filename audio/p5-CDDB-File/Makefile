# $NetBSD: Makefile,v 1.1.1.1 2006/08/23 10:38:10 jmmv Exp $

DISTNAME=	CDDB-File-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CDDB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CDDB-File/
COMMENT=	Parses a CDDB/freedb data file

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/CDDB/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
