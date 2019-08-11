# $NetBSD: Makefile,v 1.12 2019/08/11 13:20:29 wiz Exp $
#

DISTNAME=	Test-DistManifest-1.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/E/ET/ETHER/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/E/ET/ETHER/
COMMENT=	Author test that validates a package MANIFEST
LICENSE=	gnu-gpl-v1

DEPENDS+=	p5-Test-NoWarnings>=1.04:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=  # empty
PERL5_PACKLIST=	auto/Test/DistManifest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
