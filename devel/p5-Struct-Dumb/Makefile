# $NetBSD: Makefile,v 1.22 2026/07/16 19:03:20 wiz Exp $

DISTNAME=	Struct-Dumb-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Struct::Dumb
COMMENT=	Make simple lightweight record-like structures
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
TEST_DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Struct/Dumb/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
