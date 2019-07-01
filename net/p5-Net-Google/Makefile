# $NetBSD: Makefile,v 1.21 2019/07/01 21:35:49 nia Exp $

DISTNAME=		Net-Google-1.0
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/ASCOPE/Net-Google-1.0
COMMENT=		Perl module for accessing Google search engine

DEPENDS+=		p5-SOAP-Lite>=0:../../net/p5-SOAP-Lite

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/Google/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
