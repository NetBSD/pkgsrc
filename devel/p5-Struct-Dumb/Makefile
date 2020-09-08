# $NetBSD: Makefile,v 1.11 2020/09/08 13:09:55 wiz Exp $

DISTNAME=	Struct-Dumb-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/P/PE/PEVANS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Struct::Dumb
COMMENT=	Make simple lightweight record-like structures
LICENSE=	${PERL5_LICENSE}

# for make test
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

# TODO: Look for the dependencies in Build.PL.

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Struct/Dumb/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
