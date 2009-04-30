# $NetBSD: Makefile,v 1.10 2009/04/30 20:14:45 sno Exp $

DISTNAME=	CatalystX-CRUD-0.43
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-CRUD/
COMMENT=	CRUD framework for Catalyst applications
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Catalyst-Component-ACCEPT_CONTEXT>=0.06:../../www/p5-Catalyst-Component-ACCEPT_CONTEXT
DEPENDS+=	p5-Catalyst-Runtime>=5.80003:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-C3>=0:../../devel/p5-Class-C3
DEPENDS+=	p5-Data-Pageset>=0:../../devel/p5-Data-Pageset
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Emulate-Class-Accessor-Fast-[0-9]*:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Search-QueryParser-SQL>=0.005:../../databases/p5-Search-QueryParser-SQL
DEPENDS+=	p5-Sort-SQL>=0.03:../../databases/p5-Sort-SQL

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
