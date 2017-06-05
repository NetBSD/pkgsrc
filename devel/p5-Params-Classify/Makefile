# $NetBSD: Makefile,v 1.13 2017/06/05 14:23:27 ryoon Exp $

DISTNAME=	Params-Classify-0.013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Params-Classify/
COMMENT=	Perl5 module for argument type classification
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Params/Classify/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
