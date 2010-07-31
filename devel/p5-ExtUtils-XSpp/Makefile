# $NetBSD: Makefile,v 1.5 2010/07/31 08:03:30 sno Exp $

DISTNAME=	ExtUtils-XSpp-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-XSpp/
COMMENT=	XS for C++
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	{perl>=5.12.0,p5-Module-Build>=0.36000}:../../devel/p5-Module-Build
BUILD_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base
BUILD_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
DEPENDS+=	p5-ExtUtils-ParseXS>=2.22.02:../../devel/p5-ExtUtils-ParseXS

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/ExtUtils/XSpp/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
