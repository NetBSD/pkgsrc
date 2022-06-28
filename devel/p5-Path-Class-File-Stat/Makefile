# $NetBSD: Makefile,v 1.20 2022/06/28 11:33:04 wiz Exp $
#

DISTNAME=	Path-Class-File-Stat-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KARMAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Path-Class-File-Stat
COMMENT=	Cache and compare stat() calls on a Path::Class::File object
LICENSE=	${PERL5_LICENSE}

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Path/Class/File/Stat/.packlist

DEPENDS+=	p5-Path-Class>=0.15:../../devel/p5-Path-Class

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
