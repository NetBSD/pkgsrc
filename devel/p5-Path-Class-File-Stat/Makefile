# $NetBSD: Makefile,v 1.13 2017/06/05 14:23:28 ryoon Exp $
#

DISTNAME=	Path-Class-File-Stat-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KARMAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Path-Class-File-Stat/
COMMENT=	Cache and compare stat() calls on a Path::Class::File object
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Path/Class/File/Stat/.packlist

DEPENDS+=	p5-Path-Class>=0.15:../../devel/p5-Path-Class

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
