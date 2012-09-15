# $NetBSD: Makefile,v 1.20 2012/09/15 10:05:05 obache Exp $
#

DISTNAME=	Clutter-1.002
PKGNAME=	p5-${DISTNAME:tl}
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clutter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Perl bindings to the Clutter OpenGL canvas
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.2:../../devel/p5-ExtUtils-Depends
BUILD_DEPENDS+=	p5-ExtUtils-PkgConfig>=1.03:../../devel/p5-ExtUtils-PkgConfig
# for META_MERGE
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.46:../../devel/p5-ExtUtils-MakeMaker

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Clutter/.packlist

BUILDLINK_API_DEPENDS.p5-glib2+=	p5-glib2>=1.220
.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../devel/p5-pango/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/p5-cairo/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
