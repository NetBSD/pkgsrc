# $NetBSD: Makefile,v 1.8 2005/02/24 15:45:18 wiz Exp $
#

DISTNAME=	DBD-SQLite-1.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dsl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSERGEANT/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-SQLite/
COMMENT=	Perl DBI/DBD driver for sqlite databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/SQLite/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
