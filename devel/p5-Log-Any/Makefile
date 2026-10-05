# $NetBSD: Makefile,v 1.47 2026/10/05 02:24:49 wen Exp $

DISTNAME=	Log-Any-1.720
# 1.720 -> 1.72.0
PKGNAME=	p5-${DISTNAME:C/-([0-9])\.([0-9])([0-9])([0-9])/-\1.\2\3.\4/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PR/PREACTION/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Any
COMMENT=	Perl5 module to bring loggers and listeners together
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Log/Any/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
