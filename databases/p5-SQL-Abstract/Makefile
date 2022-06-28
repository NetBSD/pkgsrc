# $NetBSD: Makefile,v 1.51 2022/06/28 11:31:29 wiz Exp $

DISTNAME=	SQL-Abstract-2.000001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SQL-Abstract
COMMENT=	Generate SQL from Perl data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-Grouped>=0.10005:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Data-Dumper-Concise>=0:../../devel/p5-Data-Dumper-Concise
DEPENDS+=	p5-Getopt-Long-Descriptive>=0.091:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Hash-Merge>=0.12:../../devel/p5-Hash-Merge
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Test-Deep>=0.101:../../devel/p5-Test-Deep

BUILD_DEPENDS+=		p5-Moo-[0-9]*:../../devel/p5-Moo
BUILD_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=		p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=		p5-Tree-DAG_Node>=0:../../devel/p5-Tree-DAG_Node

PERL5_PACKLIST=		auto/SQL/Abstract/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
