# $NetBSD: Makefile,v 1.2 2020/08/31 18:07:56 wiz Exp $

DISTNAME=	DynaLoader-Functions-0.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/Z/ZE/ZEFRAM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/Z/ZE/ZEFRAM/
COMMENT=	Deconstructed dynamic C library loading
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
#PERL5_PACKLIST=	auto/DynaLoader/Function/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
