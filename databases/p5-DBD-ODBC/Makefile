# $NetBSD: Makefile,v 1.2 2009/06/14 21:23:57 sno Exp $
#

DISTNAME=	DBD-ODBC-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-ODBC/
COMMENT=	Perl DBI/DBD driver for ODBC
LICENSE=	${PERL5_LICENSE}

.include "options.mk"

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/DBD/ODBC/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
