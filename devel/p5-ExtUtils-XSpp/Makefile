# $NetBSD: Makefile,v 1.21 2019/06/30 20:15:00 nia Exp $

DISTNAME=	ExtUtils-XSpp-0.18
#                                    0.1602               -> 0.16.02
PKGNAME=	p5-${DISTNAME:C/([0-9].[0-9][0-9])([0-9][0-9])/\1.\2/}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-XSpp
COMMENT=	XS for C++
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+=	{perl>=5.14.1,p5-Module-Build>=0.38000}:../../devel/p5-Module-Build
BUILD_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base
BUILD_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
#DEPENDS+=	{perl>=5.14.1,p5-ExtUtils-ParseXS>=2.22.02}:../../devel/p5-ExtUtils-ParseXS
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=2.0}:../../security/p5-Digest-MD5

USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/ExtUtils/XSpp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
