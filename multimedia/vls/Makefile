# $NetBSD: Makefile,v 1.9 2006/03/04 21:30:16 jlam Exp $
#

DISTNAME=		vls-0.5.6
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://download.videolan.org/pub/videolan/vls/0.5.6/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLAN Server

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
# two versions of 0.5.6 out
DIST_SUBDIR=		${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--with-dvbpsi=${BUILDLINK_PREFIX.libdvbpsi}

EGDIR=			${PREFIX}/share/examples/vls
CONF_FILES=		${EGDIR}/vls.cfg ${PKG_SYSCONFDIR}/vls.cfg

.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
