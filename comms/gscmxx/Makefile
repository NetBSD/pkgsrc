# $NetBSD: Makefile,v 1.14 2011/08/14 07:43:02 obache Exp $
#

DISTNAME=	gscmxx-0.4.1
PKGREVISION=	8
CATEGORIES=	comms x11 perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gscmxx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gscmxx.sourceforge.net/
COMMENT=	Gtk+ frontend for scmxx
LICENSE=	gnu-gpl-v2

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	p5-gtk>=0.7008:../../x11/p5-gtk
DEPENDS+=	p5-Image-Size>=2.92:../../graphics/p5-Image-Size
DEPENDS+=	scmxx>=0.6:../../comms/scmxx

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/gscmxx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
