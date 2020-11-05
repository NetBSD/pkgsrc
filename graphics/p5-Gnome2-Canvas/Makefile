# $NetBSD: Makefile,v 1.47 2020/11/05 09:06:56 ryoon Exp $
#

DISTNAME=	Gnome2-Canvas-1.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	43
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for libgnomecanvas and libart
LICENSE=	gnu-lgpl-v2

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.00:../../devel/p5-ExtUtils-PkgConfig

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pkg-config

PERL5_PACKLIST=	auto/Gnome2/Canvas/.packlist

.include "../../lang/perl5/module.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/p5-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
