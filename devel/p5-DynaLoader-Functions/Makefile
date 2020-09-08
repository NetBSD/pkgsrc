# $NetBSD: Makefile,v 1.4 2020/09/08 13:16:36 wiz Exp $

DISTNAME=	DynaLoader-Functions-0.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Z/ZE/ZEFRAM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DynaLoader::Functions
COMMENT=	Deconstructed dynamic C library loading
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
#PERL5_PACKLIST=	auto/DynaLoader/Function/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
