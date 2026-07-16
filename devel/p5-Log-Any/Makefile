# $NetBSD: Makefile,v 1.46 2026/07/16 19:02:43 wiz Exp $

DISTNAME=	Log-Any-1.718
# 1.708 -> 1.70.8
PKGNAME=	p5-${DISTNAME:C/-([0-9])\.([0-9])([0-9])([0-9])/-\1.\2\3.\4/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Any
COMMENT=	Perl5 module to bring loggers and listeners together
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Log/Any/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
