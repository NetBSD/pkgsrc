# $NetBSD: Makefile,v 1.26 2023/11/14 14:02:09 wiz Exp $

DISTNAME=	Cairo-GObject-1.005
PKGNAME=	p5-${DISTNAME:tl}
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl module to integrate Cairo into the Glib type system
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

TOOL_DEPENDS+=	p5-ExtUtils-Depends>=0.2:../../devel/p5-ExtUtils-Depends
TOOL_DEPENDS+=	p5-ExtUtils-PkgConfig>=1:../../devel/p5-ExtUtils-PkgConfig

PERL5_PACKLIST=	auto/Cairo/GObject/.packlist

BUILDLINK_API_DEPENDS.p5-glib2+=	p5-glib2>=1.224
.include "../../devel/p5-glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.p5-cairo+=	p5-cairo>=1.080
.include "../../graphics/p5-cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
