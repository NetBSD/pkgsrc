# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:54 wiz Exp $

DISTNAME=	accessors-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SP/SPURKIS/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/accessors/
COMMENT=	Perl module - create accessor methods in caller's package
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/accessors/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
