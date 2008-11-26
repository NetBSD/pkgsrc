# $NetBSD: Makefile,v 1.4 2008/11/26 00:32:55 rillig Exp $
#

DISTNAME=	libopensync-0.22
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensync.org/
COMMENT=	Platform independent synchronization framework

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-python

DISTURL=${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}?format=raw
pre-fetch:
	${TEST} -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} || \
	(cd ${DISTDIR} && ${FETCH_CMD} -o ${DISTNAME}${EXTRACT_SUFX} ${DISTURL:Q})

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
