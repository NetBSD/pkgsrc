# $NetBSD: Makefile,v 1.40 2008/05/28 22:09:20 abs Exp $

DISTNAME=	DBI-1.604
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API

#REPLACE_PERL=	goferperf.pl

# Tests need Test::More
BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/DBI/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
