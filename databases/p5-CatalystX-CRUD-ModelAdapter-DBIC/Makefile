# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:43 he Exp $

DISTNAME=	CatalystX-CRUD-ModelAdapter-DBIC-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-CRUD-ModelAdapter-DBIC/
COMMENT=	CRUD for Catalyst::Model::DBIC::Schema

DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>=0:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-CatalystX-CRUD>=0.29:../../databases/p5-CatalystX-CRUD
DEPENDS+=	p5-DBIx-Class>=0:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-RDBOHelpers>=0.04:../../databases/p5-DBIx-Class-RDBOHelpers

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/ModelAdapter/DBIC/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
