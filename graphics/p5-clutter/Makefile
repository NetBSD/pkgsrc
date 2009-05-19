# $NetBSD: Makefile,v 1.3 2009/05/19 08:59:17 wiz Exp $
#

DISTNAME=	clutter-perl-0.8.2.0
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-perl/0.8/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Perl bindings to the Clutter OpenGL canvas
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.2:../../devel/p5-ExtUtils-Depends
BUILD_DEPENDS+=	p5-ExtUtils-PkgConfig>=1.03:../../devel/p5-ExtUtils-PkgConfig

WRKSRC=		${WRKDIR}/Clutter-0.820

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Clutter/.packlist

BUILDLINK_API_DEPENDS.p5-glib2+=	p5-glib2>=1.180
.include "../../devel/p5-glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter+=		clutter>=0.8.2
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../graphics/clutter-cairo/buildlink3.mk"
.include "../../graphics/p5-cairo/buildlink3.mk"
.include "../../multimedia/clutter-gst/buildlink3.mk"
.include "../../multimedia/p5-GStreamer/buildlink3.mk"
.include "../../x11/p5-gtk2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
