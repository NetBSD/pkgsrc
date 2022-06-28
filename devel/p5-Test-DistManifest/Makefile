# $NetBSD: Makefile,v 1.18 2022/06/28 11:33:23 wiz Exp $

DISTNAME=	Test-DistManifest-1.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::DistManifest
COMMENT=	Author test that validates a package MANIFEST
LICENSE=	gnu-gpl-v1

DEPENDS+=	p5-Test-NoWarnings>=1.04:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/DistManifest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
