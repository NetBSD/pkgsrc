# $NetBSD: Makefile,v 1.38 2007/07/29 16:39:43 joerg Exp $

DISTNAME=	DBI-1.56
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5dbi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API

REPLACE_PERL=	goferperf.pl

# Tests need Test::More
BUILD_DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
