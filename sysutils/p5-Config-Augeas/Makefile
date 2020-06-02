# $NetBSD: Makefile,v 1.8 2020/06/02 08:24:47 adam Exp $

DISTNAME=	Config-Augeas-1.000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RA/RAPHINK/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-Augeas
COMMENT=	Edit configuration files through Augeas C library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Config/Augeas/.packlist

.include "../../sysutils/augeas/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
