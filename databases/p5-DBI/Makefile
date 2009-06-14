# $NetBSD: Makefile,v 1.45 2009/06/14 21:03:32 sno Exp $

DISTNAME=	DBI-1.609
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL=	dbixs_rev.pl

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/DBI/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
