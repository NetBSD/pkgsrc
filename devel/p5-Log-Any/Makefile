# $NetBSD: Makefile,v 1.25 2017/12/03 08:32:15 wiz Exp $

DISTNAME=	Log-Any-1.703
PKGNAME=	p5-Log-Any-1.70.3
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
