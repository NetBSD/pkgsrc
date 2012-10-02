# $NetBSD: Makefile,v 1.12 2012/10/02 21:25:25 asau Exp $

DISTNAME=	CatalystX-CRUD-Model-RDBO-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/Model/RDBO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
