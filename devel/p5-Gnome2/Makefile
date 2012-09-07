# $NetBSD: Makefile,v 1.14 2012/09/07 19:16:26 adam Exp $
#

DISTNAME=	Gnome2-1.042
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for libgnome and libgnomeui
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.00:../../devel/p5-ExtUtils-PkgConfig

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pkg-config

PERL5_PACKLIST=	auto/Gnome2/.packlist

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/p5-Gnome2-Canvas/buildlink3.mk"
.include "../../sysutils/p5-Gnome2-VFS/buildlink3.mk"
.include "../../x11/p5-gtk2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
