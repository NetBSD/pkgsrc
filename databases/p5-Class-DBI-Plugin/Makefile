# $NetBSD: Makefile,v 1.1.1.1 2009/04/12 19:25:25 abs Exp $
#

DISTNAME=	Class-DBI-Plugin-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Class::DBI::Plugin
COMMENT=	Abstract base class for Class::DBI plugins

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-DBI>=0.90:../../databases/p5-Class-DBI

PERL5_PACKLIST=	auto/Class/DBI/Plugin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
