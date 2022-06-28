# $NetBSD: Makefile,v 1.24 2022/06/28 11:31:20 wiz Exp $

DISTNAME=	CatalystX-CRUD-ModelAdapter-DBIC-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CatalystX-CRUD-ModelAdapter-DBIC
COMMENT=	CRUD for Catalyst::Model::DBIC::Schema
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Model-DBIC-Schema-[0-9]*:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-CatalystX-CRUD>=0.42:../../databases/p5-CatalystX-CRUD
DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-RDBOHelpers>=0.04:../../databases/p5-DBIx-Class-RDBOHelpers
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-CatalystX-CRUD-Controller-REST>=0:../../www/p5-CatalystX-CRUD-Controller-REST

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/ModelAdapter/DBIC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
