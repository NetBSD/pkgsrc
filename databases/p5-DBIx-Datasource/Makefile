# $NetBSD: Makefile,v 1.19 2011/08/14 08:18:08 obache Exp $
#

DISTNAME=	DBIx-DataSource-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5dxd
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.420.am/dbix-datasource/
COMMENT=	Create and drop functions for databases

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/DBIx/DataSource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
