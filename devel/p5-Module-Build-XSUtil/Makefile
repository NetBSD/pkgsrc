# $NetBSD: Makefile,v 1.11 2018/08/22 09:44:16 wiz Exp $

DISTNAME=	Module-Build-XSUtil-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build-XSUtil
COMMENT=	Module::Build class for building XS modules
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Cwd-Guard-[0-9]*:../../devel/p5-Cwd-Guard
BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-Devel-CheckCompiler>=0.02:../../devel/p5-Devel-CheckCompiler
BUILD_DEPENDS+=	p5-File-Copy-Recursive-Reduced>=0.002:../../sysutils/p5-File-Copy-Recursive-Reduced

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/XSUtil/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
