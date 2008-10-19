# $NetBSD: Makefile,v 1.11 2008/10/19 19:17:42 he Exp $
#

DISTNAME=	gscmxx-0.4.1
PKGREVISION=	5
CATEGORIES=	comms x11 perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gscmxx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gscmxx.sourceforge.net/
COMMENT=	Gtk+ frontend for scmxx

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	p5-gtk>=0.7008:../../x11/p5-gtk
DEPENDS+=	p5-Image-Size>=2.92:../../graphics/p5-Image-Size
DEPENDS+=	scmxx>=0.6:../../comms/scmxx

PERL5_PACKLIST=	auto/gscmxx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
