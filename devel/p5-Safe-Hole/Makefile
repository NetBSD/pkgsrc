# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:26 joerg Exp $
#

DISTNAME=	Safe-Hole-0.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sho
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Safe/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/Safe-Hole/Hole.html
COMMENT=	Exec subs in the original package from within a Safe object

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Safe/Hole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
