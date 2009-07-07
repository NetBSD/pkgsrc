# $NetBSD: Makefile,v 1.3 2009/07/07 15:23:15 sno Exp $
#

DISTNAME=	DBD-ODBC-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-ODBC/
COMMENT=	Perl DBI/DBD driver for ODBC
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "options.mk"

PERL5_PACKLIST=	auto/DBD/ODBC/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
