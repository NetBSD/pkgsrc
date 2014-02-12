# $NetBSD: Makefile,v 1.58 2014/02/12 23:17:33 tron Exp $
#

DISTNAME=		icecast-2.3.3
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://downloads.xiph.org/releases/icecast/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.icecast.org/
COMMENT=		Live streaming audio server

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

BUILD_DEFS+=		ICECAST_CHROOTDIR

PKG_SYSCONFSUBDIR=	icecast
RCD_SCRIPTS=		icecast

ICECAST_LOGDIR?=	${ICECAST_CHROOTDIR}/log

ICECAST_USER?=		icecast
ICECAST_GROUP?=		icecast
PKG_USERS_VARS+=	ICECAST_USER
PKG_GROUPS_VARS+=	ICECAST_GROUP

PKG_GROUPS=		${ICECAST_GROUP}
PKG_USERS=		${ICECAST_USER}:${ICECAST_GROUP}

EGDIR=			${PREFIX}/share/examples/icecast
CONF_FILES=		${EGDIR}/icecast.xml ${PKG_SYSCONFDIR}/icecast.xml

OWN_DIRS_PERMS=		${ICECAST_CHROOTDIR} ${ICECAST_USER} ${ICECAST_GROUP} 770
OWN_DIRS_PERMS+=	${ICECAST_LOGDIR} ${ICECAST_USER} ${ICECAST_GROUP} 770

post-extract:
	${MV} ${WRKSRC}/conf/icecast.xml.in ${WRKSRC}/conf/icecast.fixme

post-install:
	${SED} \
		-e "s,@BASEDIR@,${ICECAST_CHROOTDIR},g" \
		-e "s,@LOGDIR@,log/,g" \
		-e "s,@WEBROOT@,${PREFIX}/share/icecast/web,g" \
		-e "s,@ADMINROOT@,${PREFIX}/share/icecast/admin,g" \
		-e "s,@PIDDIR@,${ICECAST_CHROOTDIR},g" \
		-e "s,@ICECAST_USER@,${ICECAST_USER},g" \
		-e "s,@ICECAST_GROUP@,${ICECAST_GROUP},g" \
		${WRKSRC}/conf/icecast.fixme > ${WRKSRC}/conf/icecast.xml
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/icecast.xml ${DESTDIR}${EGDIR}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
