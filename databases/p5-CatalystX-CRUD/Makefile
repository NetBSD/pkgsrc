# $NetBSD: Makefile,v 1.6 2008/11/29 21:42:57 seb Exp $

DISTNAME=	CatalystX-CRUD-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-CRUD/
COMMENT=	CRUD framework for Catalyst applications

DEPENDS+=	p5-Data-Pageset>=0:../../devel/p5-Data-Pageset
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Catalyst-Component-ACCEPT_CONTEXT>=0:../../www/p5-Catalyst-Component-ACCEPT_CONTEXT
DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Class-C3>=0:../../devel/p5-Class-C3
DEPENDS+=	p5-Rose-DB-Object>=0:../../databases/p5-Rose-DB-Object
DEPENDS+=	p5-Search-QueryParser-SQL>=0.005:../../databases/p5-Search-QueryParser-SQL
DEPENDS+=	p5-Sort-SQL>=0.03:../../databases/p5-Sort-SQL

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
