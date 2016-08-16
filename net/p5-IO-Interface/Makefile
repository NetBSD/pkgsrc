# $NetBSD: Makefile,v 1.26 2016/08/16 13:09:16 mef Exp $
#

DISTNAME=		IO-Interface-1.09
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Interface/
COMMENT=		IO-Interface - get and set interface characteristics
LICENSE=		artistic-2.0

PERL5_PACKLIST=		auto/IO/Interface/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
