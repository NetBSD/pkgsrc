# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:08 obache Exp $
#

DISTNAME=	Gnome2-GConf-1.044
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for the GConf configuration database
#LICENSE=	gnu-lgpl-v2

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.00:../../devel/p5-ExtUtils-PkgConfig

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pkg-config

PERL5_PACKLIST=	auto/Gnome2/GConf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
