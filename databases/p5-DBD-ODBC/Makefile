# $NetBSD: Makefile,v 1.1.1.1 2009/05/17 13:29:15 sno Exp $
#

DISTNAME=	DBD-ODBC-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-ODBC/
COMMENT=	Perl DBI/DBD driver for ODBC
LICENSE=	gnu-gpl-v2 # OR artistic

.include "options.mk"

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/DBD/ODBC/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
