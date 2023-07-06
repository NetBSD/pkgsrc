# $NetBSD: Makefile,v 1.25 2023/07/06 09:38:20 wiz Exp $

DISTNAME=	DBD-Mock-1.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBD-Mock
COMMENT=	Perl5 module with mock database driver for testing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBI>=1.3:../../databases/p5-DBI
TOOL_DEPENDS+=	p5-Module-Build-Tiny-[0-9]*:../../devel/p5-Module-Build-Tiny
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/DBD/Mock/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
