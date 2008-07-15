# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 08:42:34 abs Exp $

DISTNAME=	DBIx-Class-UUIDColumns-0.02005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?DBIx::Class::UUIDColumns
COMMENT=	Implicit uuid columns for DBIx::Class

DEPENDS+=	p5-DBIx-Class>=0.07005:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Data-UUID>=0:../../devel/p5-Data-UUID
DEPENDS+=	p5-Class-Accessor-Grouped>=0:../../devel/p5-Class-Accessor-Grouped

BUILD_DEPENDS+= p5-DBD-SQLite>=1.11:../../databases/p5-DBD-SQLite

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/UUIDColumns/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
