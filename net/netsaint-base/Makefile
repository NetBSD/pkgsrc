# $NetBSD: Makefile,v 1.12 2002/04/14 10:57:11 rh Exp $
#

DISTNAME=		netsaint-0.0.7
PKGNAME=		${DISTNAME:S/-/-base-/}
PKGREVISION=		1
MASTER_SITES=		http://www.netsaint.org/download/

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.netsaint.org/
COMMENT=		network monitor

USE_BUILDLINK_ONLY=	# defined

.include "../../net/netsaint-base/Makefile.common"

CONFIGURE_ARGS+=	--with-ping-command='/sbin/ping -n -c %d %s'

INSTALL_TARGET=		install install-config

post-configure:
	${SED} < ${FILESDIR}/netsaint-setup.sh > ${WRKDIR}/netsaint-setup.sh	\
		-e 's:@@USER@@:${NETSAINT_USER}:g'	\
		-e 's:@@GROUP@@:${NETSAINT_GROUP}:g'

post-build:
	cd ${WRKDIR}; uudecode ${FILESDIR}/logofullsize.gif.uu
	cd ${WRKDIR}; uudecode ${FILESDIR}/sblogo.gif.uu

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/netsaint
	${INSTALL_SCRIPT} ${WRKDIR}/netsaint-setup.sh ${PREFIX}/etc/netsaint
	${INSTALL_DATA} ${WRKDIR}/logofullsize.gif ${PREFIX}/share/netsaint/images
	${INSTALL_DATA} ${WRKDIR}/sblogo.gif ${PREFIX}/share/netsaint/images

.include "../../graphics/gd/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
