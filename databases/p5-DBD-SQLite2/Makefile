# $NetBSD: Makefile,v 1.5 2012/10/02 21:25:27 asau Exp $

DISTNAME=	DBD-SQLite2-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-SQLite2/
COMMENT=	Perl DBI/DBD driver for sqlite v2 databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/DBD/SQLite2/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
