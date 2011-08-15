# $NetBSD: Makefile,v 1.8 2011/08/15 05:00:02 obache Exp $

DISTNAME=	ExtUtils-XSpp-0.1602
PKGNAME=	p5-${DISTNAME:S/1602/16.02/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-XSpp/
COMMENT=	XS for C++
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	{perl>=5.14.1,p5-Module-Build>=0.38000}:../../devel/p5-Module-Build
BUILD_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base
BUILD_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
DEPENDS+=	p5-ExtUtils-ParseXS>=2.22.02:../../devel/p5-ExtUtils-ParseXS
DEPENDS+=	p5-Digest-MD5>=2.0:../../security/p5-Digest-MD5

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/ExtUtils/XSpp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
