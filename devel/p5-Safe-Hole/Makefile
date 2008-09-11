# $NetBSD: Makefile,v 1.11 2008/09/11 21:31:25 he Exp $
#

DISTNAME=	Safe-Hole-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sho
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Safe/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/dist/Safe-Hole/
COMMENT=	Exec subs in the original package from within a Safe object

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Safe/Hole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
