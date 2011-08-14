# $NetBSD: Makefile,v 1.12 2011/08/14 14:14:43 obache Exp $

DISTNAME=		Net-Google-1.0
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~ascope/Net-Google-1.0/
COMMENT=		Perl module for accessing Google search engine

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-SOAP-Lite>=0:../../net/p5-SOAP-Lite

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/Google/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
