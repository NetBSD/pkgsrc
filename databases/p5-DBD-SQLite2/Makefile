# $NetBSD: Makefile,v 1.7 2013/03/02 10:44:33 tron Exp $

DISTNAME=	DBD-SQLite2-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-SQLite2/
COMMENT=	Perl DBI/DBD driver for sqlite v2 databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/DBD/SQLite2/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
