# $NetBSD: Makefile,v 1.1.1.1 2006/07/26 13:12:34 drochner Exp $
#

DISTNAME=		gst-fluendo-mp3-0.10.2
CATEGORIES=		audio
MASTER_SITES=		http://core.fluendo.com/gstreamer/src/gst-fluendo-mp3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fluendo.com/resources/fluendo_mp3.php
COMMENT=		mp3 decoder for gstreamer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
