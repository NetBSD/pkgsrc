# $NetBSD: Makefile,v 1.29 2009/05/21 18:50:43 sno Exp $
#

DISTNAME=	Glib-${DIST_VERSION}
PKGNAME=	p5-glib2-${DIST_VERSION}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Glib/
COMMENT=	Perl bindings for Glib 2
LICENSE=	gnu-gpl-v2.1

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.00:../../devel/p5-ExtUtils-PkgConfig

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.0.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

DIST_VERSION=	1.221

PERL5_PACKLIST=	auto/Glib/.packlist

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
