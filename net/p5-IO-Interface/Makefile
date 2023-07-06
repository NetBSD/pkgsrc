# $NetBSD: Makefile,v 1.35 2023/07/06 09:41:03 wiz Exp $
#

DISTNAME=		IO-Interface-1.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IO-Interface
COMMENT=		IO-Interface - get and set interface characteristics
LICENSE=		artistic-2.0

PERL5_PACKLIST=		auto/IO/Interface/.packlist
PERL5_MODULE_TYPE=	Module::Build
USE_TOOLS=		perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
