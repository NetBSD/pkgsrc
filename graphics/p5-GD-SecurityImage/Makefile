# $NetBSD: Makefile,v 1.25.8.1 2026/08/01 23:49:36 maya Exp $

DISTNAME=	GD-SecurityImage-1.75
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	graphics security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

PATCHFILES+=		CVE-2026-13082-r1.patch
PATCH_SITES+=		https://security.metacpan.org/patches/G/GD-SecurityImage/1.75/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 security image (CAPTCHA) generator
HOMEPAGE=	https://metacpan.org/release/GD-SecurityImage
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-PerlMagick>=6.0.4:../../graphics/p5-PerlMagick

PERL5_PACKLIST=	auto/GD/SecurityImage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
