# $NetBSD: Makefile,v 1.18 2004/04/25 08:26:40 snj Exp $
#

DISTNAME=		netsaint-0.0.7
PKGNAME=		${DISTNAME:S/-/-base-/}
PKGREVISION=		3
MASTER_SITES=		http://www.netsaint.org/download/

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.netsaint.org/
COMMENT=		Network monitor

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

.include "../../net/netsaint-base/Makefile.common"

CONFIGURE_ARGS+=	--with-ping-command='/sbin/ping -n -c %d %s'

OWN_DIRS_PERMS=
.for dir in	/var/log/netsaint /var/log/netsaint/archives \
		/var/run/netsaint /var/run/netsaint/rw
OWN_DIRS_PERMS+=	${dir} ${NETSAINT_USER} ${NETSAINT_GROUP} 0755
.endfor
.undef dir

INSTALL_TARGET=		install install-config

post-build:
	cd ${WRKDIR}; uudecode ${FILESDIR}/logofullsize.gif.uu
	cd ${WRKDIR}; uudecode ${FILESDIR}/sblogo.gif.uu

post-install:
	${INSTALL_DATA} ${WRKDIR}/logofullsize.gif ${PREFIX}/share/netsaint/images
	${INSTALL_DATA} ${WRKDIR}/sblogo.gif ${PREFIX}/share/netsaint/images

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
