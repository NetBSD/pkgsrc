# $NetBSD: Makefile,v 1.16 2019/06/30 20:15:33 nia Exp $

DISTNAME=	Params-Classify-0.015
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
