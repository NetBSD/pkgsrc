# $NetBSD: Makefile,v 1.23 2020/08/31 18:10:43 wiz Exp $

DISTNAME=		Net-Google-1.0
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		12
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
