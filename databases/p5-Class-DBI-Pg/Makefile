# $NetBSD: Makefile,v 1.7 2011/08/14 08:18:05 obache Exp $
#

DISTNAME=	Class-DBI-Pg-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-Pg/
COMMENT=	Class::DBI extension for Postgres

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Class-DBI>=0.9:../../databases/p5-Class-DBI
DEPENDS+=	p5-DBD-postgresql>=1.13:../../databases/p5-DBD-postgresql

PERL5_PACKLIST=	auto/Class/DBI/Pg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
