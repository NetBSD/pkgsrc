# $NetBSD: Makefile,v 1.21 2018/08/22 09:43:13 wiz Exp $

DISTNAME=	CatalystX-CRUD-Model-RDBO-0.302
# separate the last digit by '.', like  0.31 > 0.30.2
#   (if 0.310 will be used for 0.31, no trick is necessary)
PKGNAME=	p5-${DISTNAME:C/0.([0-9][0-9])([0-9])/0.\1.\2/}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-CRUD-Model-RDBO/
COMMENT=	Rose::DB::Object CRUD
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CatalystX-CRUD>=0.43:../../databases/p5-CatalystX-CRUD
DEPENDS+=	p5-Catalyst-Runtime>=5.80000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump
DEPENDS+=	p5-Rose-DB-Object>=0:../../databases/p5-Rose-DB-Object
DEPENDS+=	p5-Rose-DBx-TestDB>=0:../../databases/p5-Rose-DBx-TestDB
DEPENDS+=	p5-Rose-DBx-Object-MoreHelpers>=0:../../databases/p5-Rose-DBx-Object-MoreHelpers
DEPENDS+=	p5-Sort-SQL>=0.05:../../databases/p5-Sort-SQL
DEPENDS+=	p5-JSON>=2:../../converters/p5-JSON

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/Model/RDBO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
