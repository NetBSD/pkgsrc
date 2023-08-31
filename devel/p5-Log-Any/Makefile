# $NetBSD: Makefile,v 1.42 2023/08/31 23:06:41 wen Exp $

DISTNAME=	Log-Any-1.717
# 1.708 -> 1.70.8
PKGNAME=	p5-${DISTNAME:C/-([0-9])\.([0-9])([0-9])([0-9])/-\1.\2\3.\4/}
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
