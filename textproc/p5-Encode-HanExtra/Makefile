# $NetBSD: Makefile,v 1.3 2018/08/22 09:46:49 wiz Exp $

DISTNAME=	Encode-HanExtra-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Encode-HanExtra/
COMMENT=	Extra sets of Chinese encodings
LICENSE=	mit

# wants both Module::Install and Module::Build
PERL5_MODULE_TYPE=	Module::Install
BUILD_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
#BUILD_DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

PERL5_PACKLIST=		auto/Encode/HanExtra/.packlist

.include "../../textproc/p5-Encode/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
