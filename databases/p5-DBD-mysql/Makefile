# $NetBSD: Makefile,v 1.43 2010/08/31 20:52:30 sno Exp $
#

DISTNAME=		DBD-mysql-4.017
PKGNAME=		p5-${DISTNAME}
#PKGREVISION=		1
SVR4_PKGNAME=		p5dmy
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://dev.mysql.com/downloads/dbi.html
COMMENT=		Perl DBI/DBD driver for MySQL databases
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Data-ShowTable>=3.3:../../devel/p5-Data-ShowTable

PERL5_PACKLIST=		auto/DBD/mysql/.packlist

MAKE_PARAMS+=		--nocatchstderr

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
