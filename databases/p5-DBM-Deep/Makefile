# $NetBSD: Makefile,v 1.36 2024/01/04 10:48:55 wiz Exp $

DISTNAME=	DBM-Deep-2.0019
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBM-Deep
COMMENT=	Pure perl multi-level hash/array DBM that supports transactions
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBM/Deep/.packlist

TOOL_DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
TOOL_DEPENDS+=	p5-Test-Deep>=0.095:../../devel/p5-Test-Deep
TOOL_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
TOOL_DEPENDS+=	p5-Test-Warn>=0.08:../../devel/p5-Test-Warn
TEST_DEPENDS+=	p5-FileHandle-Fmode-[0-9]*:../../devel/p5-FileHandle-Fmode

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
