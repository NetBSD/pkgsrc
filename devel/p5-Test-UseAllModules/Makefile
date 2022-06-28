# $NetBSD: Makefile,v 1.18 2022/06/28 11:33:31 wiz Exp $

DISTNAME=	Test-UseAllModules-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-UseAllModules
COMMENT=	Do use_ok() for all the MANIFESTed modules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/UseAllModules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
