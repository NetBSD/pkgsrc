# $NetBSD: Makefile,v 1.27.2.1 2005/02/03 23:10:06 salo Exp $
#

DISTNAME=	DBI-1.46
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbi
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API

# Tests need Test::More
BUILD_DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_REQD+=		5.6.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
