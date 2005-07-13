# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:28 jlam Exp $
#

DISTNAME=	Safe-Hole-0.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sho
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Safe/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/Safe-Hole/Hole.html
COMMENT=	Exec subs in the original package from within a Safe object

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Safe/Hole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
