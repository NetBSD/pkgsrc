# $NetBSD: Makefile,v 1.24 2017/11/29 13:32:28 wiz Exp $

DISTNAME=	Log-Any-1.702
PKGNAME=	p5-Log-Any-1.70.0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Any/
COMMENT=	Perl5 module to bring loggers and listeners together
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Log/Any/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
