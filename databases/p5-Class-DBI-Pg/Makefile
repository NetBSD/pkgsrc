# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:10 joerg Exp $
#

DISTNAME=	Class-DBI-Pg-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-Pg
COMMENT=	Class::DBI extension for Postgres

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-DBI>=0.9:../../databases/p5-Class-DBI

PERL5_PACKLIST=	auto/Class/DBI/Pg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
