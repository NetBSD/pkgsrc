# $NetBSD: Makefile,v 1.1.1.1 2007/05/23 12:44:40 markd Exp $
#

DISTNAME=	libopensync-0.22
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/attachment/wiki/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensync.org/
COMMENT=	Platform independent synchronization framework

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

DISTURL=${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}?format=raw
pre-fetch:
	${TEST} -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} || \
	(cd ${DISTDIR} && ${FETCH_CMD} -o ${DISTNAME}${EXTRACT_SUFX} ${DISTURL:Q})

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
