# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:18 joerg Exp $
#

DISTNAME=		vls-0.5.6
PKGREVISION=	2
CATEGORIES=		net
MASTER_SITES=		http://download.videolan.org/pub/videolan/vls/0.5.6/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLAN Server

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-dvbpsi=${BUILDLINK_PREFIX.libdvbpsi}

EGDIR=			${PREFIX}/share/examples/vls
CONF_FILES=		${EGDIR}/vls.cfg ${PKG_SYSCONFDIR}/vls.cfg

.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
