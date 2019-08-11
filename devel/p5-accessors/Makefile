# $NetBSD: Makefile,v 1.14 2019/08/11 13:20:44 wiz Exp $

DISTNAME=	accessors-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SP/SPURKIS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/accessors
COMMENT=	Perl module - create accessor methods in caller's package
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/accessors/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
