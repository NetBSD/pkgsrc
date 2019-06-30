# $NetBSD: Makefile,v 1.9 2019/06/30 20:15:35 nia Exp $

DISTNAME=	Path-IsDev-1.001003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KE/KENTNL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Path-IsDev
COMMENT=	Perl extension to determine if path resembles dev source tree
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Path/IsDev/.packlist

DEPENDS+=	p5-Path-Tiny>=0.004:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Class-Tiny>=0.010:../../devel/p5-Class-Tiny
DEPENDS+=	p5-File-HomeDir>0:../../devel/p5-File-HomeDir
DEPENDS+=	p5-Module-Runtime>0:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Role-Tiny>0:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Sub-Exporter>0:../../devel/p5-Sub-Exporter

# for make test
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
