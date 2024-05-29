# $NetBSD: Makefile,v 1.31 2024/05/29 16:33:44 adam Exp $
#

DISTNAME=		libassetml-1.2.1
PKGREVISION=		17
CATEGORIES=		multimedia devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ofset/}

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE=		http://www.ofset.org/assetml/
COMMENT=		Library for sharing image and audio files between projects

USE_TOOLS+=		gmake pkg-config texi2html msgfmt
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libassetml.pc.in
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
