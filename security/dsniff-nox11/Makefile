# $NetBSD: Makefile,v 1.7 2011/04/22 13:45:22 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
PKGREVISION=	3
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

INSTALLATION_DIRS+=	${PKGMANDIR}/man8
INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

post-configure:
	( cd ${WRKSRC} \
	  && grep '#define.*HAVE_SYS_QUEUE_H' config.h >/dev/null \
	  && mv missing/sys/queue.h missing/sys/queue.h.fake )

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
