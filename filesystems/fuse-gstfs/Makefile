# $NetBSD: Makefile,v 1.7 2012/09/15 10:04:35 obache Exp $
#

DISTNAME=	gstfs-0.1
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	filesystems
MASTER_SITES=	http://bobcopeland.com/gstfs/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bobcopeland.com/gstfs/
COMMENT=	On-demand, transcoding filesystem (using GStreamer pipeline)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config gmake

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PTHREAD_AUTO_VARS=	yes
REPLACE_SH=		*.sh
###
### XXX pick up the FUSE pkg-config override hook
###
do-configure:
	@${DO_NADA}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gstfs ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ogg2mp3.sh ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/mp32wav.sh ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
