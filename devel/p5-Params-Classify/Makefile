# $NetBSD: Makefile,v 1.19 2021/05/24 19:51:21 wiz Exp $

DISTNAME=	Params-Classify-0.015
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Params-Classify
COMMENT=	Perl5 module for argument type classification
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Params/Classify/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
