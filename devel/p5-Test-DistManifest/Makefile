# $NetBSD: Makefile,v 1.4 2013/05/31 12:40:48 wiz Exp $
#

DISTNAME=	Test-DistManifest-1.012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/E/ET/ETHER/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/E/ET/ETHER/
COMMENT=	Author test that validates a package MANIFEST
LICENSE=	gnu-gpl-v1

DEPENDS+=	p5-Test-NoWarnings>=1.04:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=  # empty
PERL5_PACKLIST=	auto/Test/DistManifest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
