# $NetBSD: Makefile,v 1.1.1.1 2001/01/16 15:39:42 rh Exp $
#

DISTNAME=	netsaint-0.0.6
PKGNAME=	${DISTNAME:S/-/-base-/}
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.netsaint.org/

DEPENDS+=	gd>1.8.1:../../graphics/gd

NETSAINT_USER?=	netsaint
NETSAINT_GROUP?=${NETSAINT_USER}

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--localstatedir=/var
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/netsaint
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/netsaint
CONFIGURE_ARGS+=--libexecdir=${PREFIX}/libexec/netsaint
CONFIGURE_ARGS+=--with-lockfile=/var/run/netsaint/netsaint.lock
CONFIGURE_ARGS+=--with-netsaint-user=${NETSAINT_USER}
CONFIGURE_ARGS+=--with-netsaint-grp=${NETSAINT_GROUP}

MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-configure:
	${SED} <${FILESDIR}/netsaint-setup.sh >${WRKDIR}/netsaint-setup.sh \
		-e 's:@@USER@@:${NETSAINT_USER}:g'			\
		-e 's:@@GROUP@@:${NETSAINT_GROUP}:g'
	${SED} -e 's:@@PREFIX@@:${PREFIX}:g' <${PKGDIR}/MESSAGE >${MESSAGE_FILE}

post-install:
	cd ${WRKSRC} && ${MAKE} install-config
	cd ${WRKDIR} && ${INSTALL_SCRIPT} netsaint-setup.sh ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
