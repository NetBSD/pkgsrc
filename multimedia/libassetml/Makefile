# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:16 joerg Exp $
#

DISTNAME=		libassetml-1.2.1
PKGREVISION=		1
CATEGORIES=		multimedia devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ofset/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.ofset.org/assetml/
COMMENT=		Library for sharing image and audio files between projects

BUILD_DEPENDS+=	texi2html-[0-9]*:../../textproc/texi2html

USE_DIRS+=		gnome2-1.5	# share/gnome/help
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libassetml.pc.in
GNU_CONFIGURE=		yes
INFO_FILES=		libassetml.info

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
