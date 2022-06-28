# $NetBSD: Makefile,v 1.2 2022/06/28 11:33:26 wiz Exp $

DISTNAME=		Test-Mock-Guard-0.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Mock-Guard
COMMENT=		Simple Perl5 mock test library using RAII
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Mock/Guard/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
