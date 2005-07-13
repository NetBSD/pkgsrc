# $NetBSD: Makefile,v 1.32 2005/07/13 18:01:21 jlam Exp $

DISTNAME=	DBI-1.48
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API

# Tests need Test::More
BUILD_DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_REQD+=		5.6.0
PERL5_PACKLIST=		auto/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
