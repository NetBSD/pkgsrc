# $NetBSD: Makefile,v 1.1.1.1 2012/05/31 16:44:52 imil Exp $
#

DISTNAME=	Test-DistManifest-1.012
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/E/ET/ETHER/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/E/ET/ETHER/
COMMENT=	Author test that validates a package MANIFEST
LICENSE=	gnu-gpl-v1

DEPENDS+=	p5-Test-NoWarnings>=1.04:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=  # empty
PERL5_PACKLIST=	auto/Test/DistManifest/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
