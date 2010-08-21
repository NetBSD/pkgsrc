# $NetBSD: Makefile,v 1.5 2010/08/21 16:32:54 seb Exp $
#

DISTNAME=	Class-DBI-Pg-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-Pg/
COMMENT=	Class::DBI extension for Postgres

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-DBI>=0.9:../../databases/p5-Class-DBI

PERL5_PACKLIST=	auto/Class-DBI-Pg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
