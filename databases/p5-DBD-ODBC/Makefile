# $NetBSD: Makefile,v 1.4 2009/09/12 18:54:50 sno Exp $
#

DISTNAME=	DBD-ODBC-1.23
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

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
