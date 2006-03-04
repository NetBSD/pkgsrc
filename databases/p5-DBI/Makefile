# $NetBSD: Makefile,v 1.35 2006/03/04 21:29:09 jlam Exp $

DISTNAME=	DBI-1.50
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API

# Tests need Test::More
BUILD_DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
