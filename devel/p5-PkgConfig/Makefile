# $NetBSD: Makefile,v 1.5 2022/06/28 11:33:07 wiz Exp $

DISTNAME=		PkgConfig-0.25026
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=		otis@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/PkgConfig
COMMENT=		Pure-Perl Core-Only replacement for pkg-config
LICENSE=		${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-extract
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	lib/PkgConfig.pm
SUBST_SED.paths=	-e 's,/usr/bin,${PREFIX}/bin,g'

PERL5_PACKLIST=		auto/PkgConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
