# $NetBSD: Makefile,v 1.42 2008/07/24 09:28:47 rhaen Exp $

DISTNAME=	DBI-1.607
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API

REPLACE_PERL=	dbixs_rev.pl

# Tests need Test::More
BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/DBI/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
