# $NetBSD: Makefile,v 1.28 2007/02/15 21:46:53 rillig Exp $
#

DISTNAME=		netsaint-0.0.7
PKGNAME=		${DISTNAME:S/-/-base-/}
PKGREVISION=		8
MASTER_SITES=		http://www.netsaint.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.netsaint.org/
COMMENT=		Network monitor


.include "../../net/netsaint-base/Makefile.common"

CONFIGURE_ARGS+=	--with-ping-command='/sbin/ping -n -c %d %s'
CONFIGURE_ARGS+=	--with-mail=${MAIL_CMD:Q}
USE_TOOLS+=		mail:run

OWN_DIRS_PERMS=
.for dir in	/var/log/netsaint /var/log/netsaint/archives \
		/var/run/netsaint /var/run/netsaint/rw
OWN_DIRS_PERMS+=	${dir} ${NETSAINT_USER} ${NETSAINT_GROUP} 0755
.endfor

INSTALL_TARGET=		install install-config

post-build:
	cd ${WRKDIR} && uudecode ${FILESDIR}/logofullsize.gif.uu
	cd ${WRKDIR} && uudecode ${FILESDIR}/sblogo.gif.uu

post-install:
	${INSTALL_DATA} ${WRKDIR}/logofullsize.gif ${PREFIX}/share/netsaint/images
	${INSTALL_DATA} ${WRKDIR}/sblogo.gif ${PREFIX}/share/netsaint/images

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
