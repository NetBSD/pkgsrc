# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:10 tv Exp $
#

DISTNAME=		tunesbrowser-0.1.5
PKGREVISION=	1
CATEGORIES=		audio
MASTER_SITES=		http://crazney.net/programs/itunes/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://crazney.net/programs/itunes/libopendaap.html
COMMENT=		Front-end for DAAP client

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

DEPENDS+=		mad>=0.15.0b:../../audio/mad

.include "../../audio/gst-plugins-artsd/buildlink3.mk"
.include "../../audio/gst-plugins-esound/buildlink3.mk"
.include "../../audio/gst-plugins-mad/buildlink3.mk"
.include "../../audio/libopendaap/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
