# $NetBSD: Makefile,v 1.39 2020/03/20 11:57:51 nia Exp $

DISTNAME=	Cairo-1.106
PKGNAME=	p5-${DISTNAME:tl}
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings to the cairo graphics library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.2:../../devel/p5-ExtUtils-Depends
BUILD_DEPENDS+=	p5-ExtUtils-PkgConfig>=1:../../devel/p5-ExtUtils-PkgConfig

PERL5_PACKLIST=	auto/Cairo/.packlist

.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
