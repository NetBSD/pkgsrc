# $NetBSD: Makefile,v 1.3 2007/06/08 13:03:22 wiz Exp $
#

DISTNAME=		gst-fluendo-mp3-0.10.6
CATEGORIES=		audio
MASTER_SITES=		http://core.fluendo.com/gstreamer/src/gst-fluendo-mp3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fluendo.com/resources/fluendo_mp3.php
COMMENT=		mp3 decoder for gstreamer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
